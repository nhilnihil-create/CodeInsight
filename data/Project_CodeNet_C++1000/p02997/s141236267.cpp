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

    if (k > (n-1)*(n-2)/2){
        cout << -1 << endl;
        return 0;
    }

    vector<P> ans;

    rep(i, n-1) ans.push_back(make_pair(1, i+2));

    int cnt = (n-1)*(n-2)/2 - k;

    if (cnt == 0) {
        cout << ans.size() << endl;
        rep(j, ans.size()) cout << ans[j].first << " " << ans[j].second << endl;
        return 0;
    }

    for(int p = 2; p <= n; p++){
        for(int q = p+1; q <= n; q++){
            ans.push_back(make_pair(p,q));
            cnt--;
            if (cnt == 0) {
                cout << ans.size() << endl;
                rep(j, ans.size()) cout << ans[j].first << " " << ans[j].second << endl;
                return 0;
            }
        }
    }
}
