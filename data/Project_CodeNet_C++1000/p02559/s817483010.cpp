#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
vl BIT(500500);
ll n , q;
void add(ll ind , ll x){
  for(ll i = ind; i <= n; i += (i & -i)){
    BIT[i] += x;
  }
}
      
ll sum(ll ind){
  ll ret = 0;
  for(ll i = ind; i > 0; i -= (i & -i)){
    ret += BIT[i];
  }
  return ret;
}

signed main(){
	//cout << fixed << setprecision(10);
    cin >> n >> q;
    rep(i,1,n+1){
      ll a; cin >> a;
      add(i , a);
    }
    while(q--){
      ll t; cin >> t;
      ll a , b; cin >> a >> b;
      if(t == 0){
        add(a+1 , b);
      }
      else{
        cout << sum(b) - sum(a) << endl;
      }
    }
  

	return 0;
}
