#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define MOD 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}


ll pow2( ll n, ll cnt ){
  if( cnt == 1 ) return n;
  if( cnt == 0 ) return 1;
  if( cnt%2 == 0 ){
    ll tmp = pow2(n,cnt/2);
    return tmp%MOD*tmp%MOD;
  }else{
    ll tmp = pow2(n,cnt/2);
    return tmp%MOD*n%MOD*tmp%MOD;
  }
}
 

ll fac( ll n, ll cnt ){
  if( cnt == 1 ) return n;
  if( cnt == 0 ) return 1;
  return fac(n-1,cnt-1)%MOD*n%MOD;
}


void test_case() {

    ll n, a, b;
    cin>>n >>a >>b;

    ll xa = fac(n,a);
  ll ya = fac(a,a);
  ll amod = xa*pow2(ya,MOD-2)%MOD;
  if( amod < 0 ) amod += MOD;

 
  // nCb mod MOD を計算
  ll xb = fac(n,b);
  ll yb = fac(b,b);
  ll bmod = xb*pow2(yb,MOD-2)%MOD;
  if( bmod < 0 ) bmod += MOD;

 
  ll ans = pow2(2,n);
  if( ans < 0 ) ans += MOD;
  ans -= amod + bmod + 1;
 
  while( ans < 0 )
    ans += MOD;
 
  cout << ans << endl;





    






}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t = 1;
    //cin >> t;
    while(t--)
    {   
        test_case();
    }
}
