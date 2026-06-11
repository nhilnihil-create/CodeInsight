#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    //llで入力
    ll a,intb;cin>>a;
    
    //doubleで入力
    double b;cin>>b;

    //bを整数として処理する
    b+=0.005;
    b*=100;
    intb=(ll)(b);

    cout<<(a*intb)/100<<endl;
    return 0;
}
