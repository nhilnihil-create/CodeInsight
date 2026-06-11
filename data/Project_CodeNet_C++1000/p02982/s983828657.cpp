#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n,d;
    cin >> n >> d;
    int point[n][d];
    rep(i,n) rep(j,d) cin >> point[i][j];
    int p[100000];
    rep(i,100000) p[i] = 0;
    rep(i,160) p[i*i] = 1;
    int ans = 0;
    rep(i,n) {
        for(int j = i+1; j < n; j++) {
            int dist = 0;
            for (int k = 0; k < d;  k++) {
                dist += (point[i][k] - point[j][k])*(point[i][k] - point[j][k]);
            }
            if (p[dist]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}