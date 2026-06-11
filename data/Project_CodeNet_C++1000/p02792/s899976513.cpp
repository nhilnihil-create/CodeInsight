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

ll n,ans=0;
void solve(string s,string t){
    for (ll i=0;i<10;i++){

    }
}

int main(){
    cin >> n;
    string s;
    ll ans[10][10],count=0;
    memset(ans,0,sizeof(ans));
    for (ll i=1;i<=n;i++){
        s=to_string(i);
        ans[s[0]-'0'][i%10]++;
    }
    for (ll i=1;i<10;i++){
        for (ll j=1;j<10;j++){
            count+=ans[i][j]*ans[j][i];
        }
    }
    cout << count << endl;
    return 0;
}