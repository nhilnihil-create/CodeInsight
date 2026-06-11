#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, d,x,cnt=0;
    double nn = 0.0;
    cin >> n >> d;
    vector<vector<int>>arr(n, vector<int>(d));
    rep(i, n)rep(j, d) {
        cin >> x;
        arr[i][j] = x;
    }

    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            nn = 0;
            rep(k, d) {
                nn += abs(arr[i][k] - arr[j][k]) * abs(arr[i][k] - arr[j][k]);
            }
            nn = sqrt(nn);
            if (fmod(nn,1)== 0)cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
