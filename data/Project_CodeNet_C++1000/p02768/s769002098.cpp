#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll MOD = 1000000007;
ll INF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

//-----------------------------------------

ll power_mod(ll x, ll y, ll m){
  ll res = 1;
  if(y>0){
    res = power_mod(x,y/2,m);
    if(y%2==0) res = (res*res)%m;
    else res = (((res*res)%m)*x)%m;
  }
  return res;
}


long long nCk(int n, int k){
    long long res = 1 ;
    for(int i=0;i<k;i++){
        res *= (n-i) ;
        res %= MOD ;
    }
    long long tmp = 1 ;
    for(int i=0;i<k;i++){
        tmp *= (i+1) ;
        tmp %=MOD ;
    }
    tmp = power_mod(tmp,MOD-2,MOD) ;
    res *= tmp ;
    res %= MOD ;
    return res ;
}
//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);


   ll n, a, b;
   cin >> n >> a >> b;

   ll ans = power_mod(2,n,MOD) - 1;
   ans -= nCk(n,a);
   ans -= nCk(n,b);
   ans += MOD * MOD;
   cout << (ans % MOD) <<endl;




  return 0;
}

