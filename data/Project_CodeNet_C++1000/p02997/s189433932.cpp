#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n, k;
    cin >> n >> k;

    if (k > (n-1)*(n-2)/2) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int,int>> vp;
    rep(i, n-1) vp.push_back({1, i+2});

    int d = (n-1)*(n-2)/2 - k;
    if (d == 0){
        cout << vp.size() << endl;
        for(auto e : vp) cout << e.first << " " << e.second << endl;
        return 0;
    }

    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vp.push_back({i,j});
            d--;
            if (d == 0){
                cout << vp.size() << endl;
                for(auto e : vp) cout << e.first << " " << e.second << endl;
                return 0;
            }
        }
    }

    return 0;
}
