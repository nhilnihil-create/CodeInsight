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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m);
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];
    vector<ll> sum(m+1,0);
    rep(i,m){
        sum[i+1]=sum[i]+b[i];
    }
    //debug(sum);
    ll ans=upper_bound(ALL(sum),k)-sum.begin();
    ans--;
    ll s=0;
    rep(i,n){
        s+=a[i];
        ll kk=k-s;
        if(kk>=0){
            ll temp = upper_bound(ALL(sum), kk) - sum.begin();
            temp--;
            chmax(ans,i+1+temp);
        }
    }
    cout<<ans<<"\n";
}
