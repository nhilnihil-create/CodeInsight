#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<int,int> P;
typedef pair<P,ll> PP;
using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    ll m,d;
    cin >> m >> d;
    ll ans = 0;
    for(int i=1;i<=m;i++){
        for(int j=10;j<=d;j++){
            int d1 = j%10;
            int d10 = (j/10)%10;
            if(d1>=2&&d10>=2&&d1*d10==i)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}