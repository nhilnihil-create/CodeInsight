#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
#define MAX_N 100100
#define MOD 998244353
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}

vector<ll> ki[1000000];
ll c[1000000];
bool visited[1000000];
void dfs(ll p,ll x){
    if (p!=-1)c[x]+=c[p];
    for (ll i=0;i<ki[x].size();i++){
        if (ki[x][i]==p)continue;
        dfs(x,ki[x][i]);
    }
}

int main(){
    ll n,q;
    cin >> n >> q;
    fill(c,c+n,0);
    for (ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        ki[a].push_back(b);
        ki[b].push_back(a);
    }
    for (ll i=0;i<q;i++){
        ll p,x;
        cin >> p >> x;
        p--;
        c[p]+=x;
    }
    dfs(-1,0);
    for (ll i=0;i<n;i++){
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}