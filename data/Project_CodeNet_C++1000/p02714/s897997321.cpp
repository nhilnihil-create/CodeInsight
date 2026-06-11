#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;
auto clk=clock();
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define vreset(v) fill(v.start(),v.end(),0)
#define areset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define max3(a,b,c) max(a,max(b,c))
#define nl '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl

// Error detection
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
//use the inside loops mainly to trace i,j etc value

#define debug(vec) for(auto v : vec) cerr << v << " "; cerr << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
typedef set<int> s32;

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //(int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int mod = 1000000007;

// mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
// int rng(int lim) {
// 	uniform_int_distribution<int> uid(0,lim-1);
// 	return uid(rang);
// }

// int powm(int a, int b) {
// 	int res=1;
// 	while(b) {
// 		if(b&1)
// 			res=(res*a)%mod;
// 		a=(a*a)%mod;
// 		b>>=1;
// 	}
// 	return res;
// }

int main(){
    fastio;
    
    int n;
    cin>>n;
    string s;
    ll count=0;
    cin>>s;
    ll r=0,bb=0,g=0;
    forstl(i,s){
        if(i=='R') r++;
        else if(i=='G') g++;
        else bb++;
    }
    ll ans = r*g*bb; 

    forsn(i, 0, n - 1) {
        forsn(j, i + 1, n) {
            ll k = 2 * j - i;
            if (k < n && s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) {
                ans--;
            }
        }
    }
    
    cout<<ans<<nl;
    
    #ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif

    return 0;
}