#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;
 
int main() {
    int n;
    cin >> n;
    int d[n][2];
    rep(i,n) cin >> d[i][0] >> d[i][1];
    rep(i, n-2) {
        if (d[i][0] == d[i][1] && d[i+1][0] == d[i+1][1] && d[i+2][0] == d[i+2][1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}