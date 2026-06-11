#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    map<ll,ll> mii1,mii2;
    rep(i,n){
        int x;
        cin >> x;
        mii1[i + x]++;
        mii2[i - x]++;
    }
    ll ans = 0;
    for(auto u : mii1){
        ans += u.second  * mii2[u.first];
    }
    cout << ans << endl;
    return 0;

}