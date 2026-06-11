#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using Grid = vector<vector<int>>;
using vi = vector<int>;

int main(){
    int N;
    cin >> N;
    vi v(N);
    rep(i, N) cin >> v[i];
    vector<int> lsum(N + 1, 0);
    vector<int> rsum(N+1, 0);
    lsum[0] = 0;
    for (int i = 1; i <= N; i++) {
        lsum[i] = v[i - 1] + lsum[i - 1];
    }
    rsum[0] = 0;
    for (int i = 1; i <= N; i++) {
        rsum[i] = v[N - i] + rsum[i - 1];
    }
    int ans = INT_MAX;
    rep2(i, N) {
        ans = min(ans, abs(lsum[i] - rsum[N - i]));
    }
    cout << ans << endl;
}