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
 ll n;
 ll a[MAXN], b[MAXN];
 int main(){
    cin >> n;
    for(ll i = 1; i <= n; ++i){
    	cin >> a[i] >> b[i];
	}
	for(ll i = 1; i + 2 <= n; ++i){
		if(a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2])return cout << "Yes", 0;
	}
	cout << "No";
 }