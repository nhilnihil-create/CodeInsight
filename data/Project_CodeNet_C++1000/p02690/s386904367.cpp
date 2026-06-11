#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

ll f(ll a, ll b) {
  return pow(a, 5) - pow(b, 5);
}

int main() {
  ll x;
  cin >> x;
  
  for (ll i = -1000; i <= 1000; ++i) {
    for (ll j = -1000; j <= 1000; ++j) {
      ll value = f(i, j);
      if (value == x) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  // rep(i, 1001) {
  //   cout << pow(i, 5) - pow(i - 1, 5) << endl;
  // }

}