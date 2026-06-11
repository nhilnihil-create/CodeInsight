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

int main(){
    ll n,ans=0;
    string s;
    cin >> n >> s;
    for (ll i=0;i<10;i++){
        for (ll j=0;j<10;j++){
            for (ll k=0;k<10;k++){
                char a[3];
                a[0]='0'+i;
                a[1]='0'+j;
                a[2]='0'+k;
                ll c=0;
                for (ll l=0;l<s.size();l++){
                    if (a[c]==s[l]){
                        a[c]='0'-1;
                        c++;
                    }
                }
                bool f=true;
                for (ll l=0;l<3;l++){
                    if (a[l]!='0'-1)f=false;
                }
                if (f)ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}    
