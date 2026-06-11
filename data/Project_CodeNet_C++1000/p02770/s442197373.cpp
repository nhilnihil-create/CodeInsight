#include <bits/stdc++.h>
using namespace std;

int main(){ 
  int64_t k, q;
  vector<int64_t> d(5010);
  cin >> k >> q;
  for(int i=1; i<=k; i++) cin >> d[i];

  for(int query=0; query<q; query++){
    int64_t n, x, m, zeros = 0, ans = 0, sum = 0, kuriagari = 0;
    cin >> n >> x >> m;
    x %= m;

    vector<int64_t> dmod(5010);
    for(int i=1; i<=k; i++){
      dmod[i] = d[i] % m;
      if(dmod[i] == 0) zeros++;
      sum += dmod[i];
    }

    int64_t loops = (n-1) / k, rest = (n-1) % k;

    kuriagari += (sum * loops + x) / m;
    int64_t nokori = (sum * loops + x) % m;
    for(int i=1; i<=rest; i++){
      nokori += dmod[i];
      if(nokori >= m){
        nokori %= m;
        kuriagari++;
      }
    }
  

    ans += loops * (k-zeros);

    for(int i=1; i<=(n-1)%k; i++){
      if(dmod[i] % m != 0) ans++;
    }

    ans -= kuriagari;

    cout << ans << endl;
  }
}