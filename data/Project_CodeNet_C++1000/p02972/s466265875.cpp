#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const long long INF = 1LL << 60;
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
    ll a[n];
    for (ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll x[n];
    vector<ll> ans;
    for (ll i=n;i>0;i--){
        ll c=0;
        for (ll j=i*2;j<=n;j+=i){
            c+=x[j-1];
        }
        if (c%2!=a[i-1]){
            x[i-1]=1;
            ans.push_back(i);
        }else{
            x[i-1]=0;
        }
    }
    cout << ans .size() << endl;
    for (ll i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    if (ans.size())cout << endl;
    return 0;
}
