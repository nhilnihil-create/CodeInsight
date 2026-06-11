#include<iostream>
#include<vector>
using namespace std;

int main(){
  int k, q;
  cin >> k >> q;

  vector<long long> d(k);
  for(auto& x: d){
    cin >> x;
  }

  for(int q_ = 0; q_ < q; q_++){
    long long n, x, m;
    cin >> n >> x >> m;

    vector<long long> d_mod(k), d_sum(k + 1, 0);
    long long d_mod_0_cnt = 0;
    for(int i = 0; i < k; i++){
      d_mod[i] = d[i] % m;
      if(d_mod[i] == 0){
        d_mod_0_cnt++;
      }
      d_sum[i + 1] = d_sum[i] + d_mod[i];
    }

    long long ans_comp = 0;

    long long a_n = x;
    a_n += (n - 1) / k * d_sum[k];
    for(int i = 0; i < (n - 1) % k; i++){
      a_n += d_mod[i];
    }
    // a_n >= pm, a_0 = qm
    long long p = a_n / m, q = x / m;

    ans_comp += (p - q);

    ans_comp += (n - 1) / k * d_mod_0_cnt;
    for(int i = 0; i < (n - 1) % k; i++){
      if(d_mod[i] == 0){
        ans_comp++;
      }
    }

    cout << (n - 1) - ans_comp << endl;
  }
}
