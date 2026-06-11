#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    vector<vector<int>> ans(H,vector<int>(W));
    for (int i=0;i<B;i++){
        for (int j=0;j<A;j++){
            ans[i][j] = 1;
        }
    }
    for (int i=B;i<H;i++){
        for (int j=A;j<W;j++){
            ans[i][j] = 1;
        }
    }
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cout << ans[i][j];
            if (j==W-1) cout << "\n";
        }
    }
}