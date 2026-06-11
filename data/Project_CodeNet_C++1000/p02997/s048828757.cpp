//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n, m,k;
vector<vector<ll>> v;
void write_r(){
    ll sum=0;
    rep(i,n){
        sum+=v[i].size();
    }
    cout<<sum<<"\n";
    rep(i,n){
        rep(j,v[i].size()){
            cout<<i+1<<" "<<v[i][j]+1<<"\n";
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>k;
    ll now=(n-2)*(n-1)/2;
    if((n-2)*(n-1)/2<k)return cout<<-1<<"\n",0;
    v.resize(n);
    for(int i=1;i<n;i++){
        v[0].push_back(i);
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(now==k){
                write_r();
                return 0;
            }
            now--;
            v[i].push_back(j);
        }
    }
    write_r();
}
