#include<bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
//const ll INF = (1LL << 60);
//const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/

/******** User-defined Function *******/
map<ll,int>prime_factor(ll n){
	map<ll,int>res;
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			res[i]++;
			n/=i;
		}
	}
	if(n!=1)res[n]++;
	return res;
}
/**************************************/

/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;

    map<ll,int> mp;
    mp = prime_factor(n);

    ll ans = 0;
    for(auto x: mp){
        ll tmp = x.second;
        for(int i=1;;i++){
            if(tmp-i>=0){
                ans++;
                tmp -= i;
            }else{
                break;
            }
        }
    }

    // for(auto x: mp){
    //     cout << x.first << " " << x.second << endl;
    // }

    cout << ans << endl;

    return 0;
}
/********  Main() Ends Here *************/
