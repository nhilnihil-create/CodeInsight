#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


ll INF = 1e9;
ll NIL = -1;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}

//-----------------------------------------
long long power_mod(long long x, long long y, long long m){
    long long res = 1 ;
    if(y>0){
        res = power_mod(x,y/2,m) ;
        if(y%2==0){
            res = (res*res)%m ;
        }
        else{
            res = (((res*res)%m)*x)%m ;
        }
    }
    return res ;
}
//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    ll n = SZ(s);
    reverse(ALL(s));
    vvll dp(n,vll(13,0));

    if(s[0]!='?'){
        dp[0][s[0]-'0'] = 1;
    }
    else{
        REP(i,10){
            dp[0][i] = 1;
        }
    }

    for(ll i=1;i<n;i++){
        char c = s[i];
        ll hog = power_mod(10,i,13);
        if(c!='?'){
            REP(j,13){
                dp[i][(j+hog*(c-'0'))%13] += dp[i-1][j];
                dp[i][(j+hog*(c-'0'))%13] %= MOD;
            }
        }
        else{
            REP(j,13){
                REP(k,10){
                    dp[i][(j+hog*k)%13] += dp[i-1][j];
                    dp[i][(j+hog*k)%13] %= MOD;
                }
            }
        }
    }


    cout << dp[n-1][5] <<endl;

    
    return 0;
}

