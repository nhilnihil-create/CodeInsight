#include <bits/stdc++.h>

#include <cstdio>
#include <vector>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef long long ll;

void solve(long long N, long long M) {
    vector<pair<int, int>> ans;
    if (N % 2 == 1) {
        for (int l = 1, r = N - 1; l < r; l++, r--) {
            ans.emplace_back(l, r);
        }
    } else {
        bool flag = false;
        for (int l = 1, r = N - 1; l < r; l++, r--) {
            if (!flag && r - l <= N / 2) {
                r--;
                flag = true;
            }
            ans.emplace_back(l, r);
        }
    }
    rep(i, M) { printf("%d %d\n", ans[i].first, ans[i].second); }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    solve(N, M);
    return 0;
}
