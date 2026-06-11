#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, ans = 0;
  cin >> N;
  vector<ll> L(N, 0);
  rep(i, N)
    cin >> L[i];
  sort(all(L));
  rep(i, N-2){
    for(ll j = i+1; j < N-1; j++){
      for(ll k = j+1; k < N; k++){
        ll a=L[i];
        ll b=L[j];
        ll c=L[k];
        if (a==b || b==c || c==a)
          continue;
        if (a + b > c){
          ans++;
//          cout<<a<<" "<<b<<" "<<c<<endl;
        }
      }
    }
  }
  cout << ans << endl;
}
