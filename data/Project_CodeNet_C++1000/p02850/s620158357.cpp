#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
#define PI 3.141592653589793
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const ll INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main(){
    ll n;
    cin >> n;
    pair<ll,ll> g[n];
    vector<ll> ki[n];
    for (ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        g[i]=make_pair(a-1,b-1);
        ki[b-1].push_back(i);
        ki[a-1].push_back(i);
    }
    ll color[n];
    fill(color,color+n,-1);
    queue<ll> que;
    que.push(0);
    color[0]=1;
    bool visited[n];
    fill(visited,visited+n,true);
    visited[0]=false;
    while(!que.empty()){
        ll pa=que.front();
        ll x=g[pa].first;
        que.pop();
        ll p=1;
        for (ll i=0;i<ki[x].size();i++){
            if (visited[ki[x][i]]){
                if (p==color[pa])p++;
                que.push(ki[x][i]);
                color[ki[x][i]]=p;
                p++;
                visited[ki[x][i]]=false;
            }
        }
        x=g[pa].second;
        p=1;
        for (ll i=0;i<ki[x].size();i++){
            if (visited[ki[x][i]]){
                if (p==color[pa])p++;
                que.push(ki[x][i]);
                color[ki[x][i]]=p;
                p++;
                visited[ki[x][i]]=false;
            }
        }
    }
    ll ans=0;
    for (ll i=0;i<n-1;i++){
        ans=max(ans,color[i]);
    }
    cout << ans << endl;
    for (ll i=0;i<n-1;i++){
        cout << color[i] << endl;
    }
    return 0;
}