#include <bits/stdc++.h>
//in the name of god;;
using namespace std;
////////////////////////////////////////////////////////
typedef long long ll;                                 //
typedef long double ld;                               //
////////////////////////////////////////////////////////
#define pb push_back                                  //
#define vc vector<ll>                                 //
#define vpl vector<pair<ll, ll> >                     //
#define d double                                      //
#define So(v) sort(v.begin(), v.end())                //
#define Y cout << "YES\n"                             //
#define N cout << "NO\n"                              //
#define rep(x, n) for(ll i = x; i <= n; ++i)          //
#define repp(x, n) for(ll i = n; i >= x; --i)         //
////////////////////////////////////////////////////////
const ll MAXN = 1e6;                                 ///
//////////////////////////////////////////////////////// 
 
 int main(){
    ll n, ans = 0;
    cin >> n;
  //  1| 1 2 3 4 5 6 7 8 ... 99; 99;
  //  2| 1 2 3 4 5 6 7 8 ... 49; 49;
  //  3| 1 2 3 4 5 6 7 8 ... 33; 33;
  //  ...
  //  99 1;
  for(ll i = 1; i < n; ++i){
  	ll g = (n % i == 0 ? n/i-1 : n/i);
  	ans += (g < 0 ? 2 : g);
  }
    cout << ans;
 }