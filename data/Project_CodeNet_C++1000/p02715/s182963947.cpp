//#include <tourist>
#include <bits/stdc++.h>
    using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
//-std=gnu++17
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n, k;
const ll M = pow(10, 9) + 7;

vector<ll> fac(1000001);  //n!(mod M)
vector<ll> ifac(1000001); //k!^{M-2} (mod M)
ll mpow(ll x, ll n)
{ //x^n(mod M)
    ll ans = 1;
    while (n != 0)
    {
        if (n & 1)
            ans = ans * x % M;
        x = x * x % M;
        n = n >> 1;
    }
    return ans;
}
//conbination
ll comb(ll a, ll b)
{ //aCb(mod M)
    if (a == 0 && b == 0)
        return 1;
    if (a < b || a < 0)
        return 0;
    ll tmp = ifac[a - b] * ifac[b] % M;
    return tmp * fac[a] % M;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<ll> v(k+1);
    for(ll i=0;i<k;i++){
        v[i+1]=mpow(k/(i+1),n);
    }
    //debug(v);
    vector<ll> ans(k+1);
    ll ans_t=0;
    for(ll i=k;i>=1;i--){
        ll temp=v[i];
        ll j=1;
        while(true){
            j++;
            if(i*j>k){
                break;
            }
            temp-=ans[i*j];
            temp=(temp+MOD)%MOD;
        }
        ans[i]=temp;
        ans_t+=temp*i;
        ans_t%=MOD;
    }
    cout<<ans_t<<"\n";
}
