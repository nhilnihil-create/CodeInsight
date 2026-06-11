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
const ll INF = 1LL << 56;
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
    n--;
    vector<char> s;
    s.push_back('a'+(n%26));
    n/=26;
    while(n){
        n--;
        s.push_back('a'+(n%26));
        n/=26;
    }
    for (ll i=0;i<s.size();i++){
        cout << s[s.size()-1-i];
    }
    cout << endl;
    return 0;
}
