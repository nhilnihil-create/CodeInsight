#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define LINF 1LL << 60

int main(){
  int n, k;
  while(cin >> n >> k && n != 0){
    vector<ll> a(n);
    vector<ll> sum(n + 1, 0);
    for(int i = 0; i < n; ++i){
      cin >> a[i];
      sum[i + 1] = sum[i] + a[i];
    }

    ll ans = -LINF;
    for(int i = 0; k + i <= n; ++i){
      ll tmp = sum[k + i] - sum[i];
      if(tmp > ans)ans = tmp;
    }

    cout << ans << endl;
  }
}

