#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

const ll mod = 1000000007;


int main() {
    int n,k;
    cin >> n >> k;
    if ((n-1)*(n-2)/2 < k) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> ans(0);
    rep(i,n-1) {
        ans.push_back({i+1, n});
    }
    // rep(i,n-1) cout << ans[i].first << ans[i].second << endl;
    int cnt = (n-1)*(n-2)/2;
    rep(i,n-1) {
        for (int j = i+1; j < n-1; j++) {
            if (cnt == k) {
                cout << ans.size() << endl;
                for (pair<int, int> x : ans) {
                    printf("%d %d\n", x.first, x.second);
                }
                return 0;
            }
            ans.push_back({i+1,j+1});
            cnt--;
        }
    }
    if (cnt == k) {
        cout << ans.size() << endl;
        for (pair<int, int> x : ans) {
            printf("%d %d\n", x.first, x.second);
        }
    }
    return 0;
}