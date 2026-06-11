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
template <typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    double ans;
    ll a,b,x;cin>>a>>b>>x;

    if(x<=a*b*a/2.0){
        ans=atan((2*x+.0)/(a*b*b));
    }else{
        ans=atan((a*a*a+.0)/(2*b*a*a-2*x));
    }

    cout<<fixed;

    cout<<setprecision(10)<<90-ans*180/pi<<endl;
    return 0;
}