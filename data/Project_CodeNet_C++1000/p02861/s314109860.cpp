#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<pint> xy(N);
    for (int i = 0; i < N; ++i) cin >> xy[i].first >> xy[i].second;
    double res = 0;
    vector<int>v(N);
    for (int i = 0; i < N; ++i) v[i] = i;

    do {
        for (int i = 0; i < N-1; ++i) {
            double dx = xy[v[i]].first - xy[v[i+1]].first;
            double dy = xy[v[i]].second - xy[v[i+1]].second;
            res += pow(dx*dx + dy*dy, 0.5);
        }
    } while(next_permutation(v.begin(), v.end()));
    int count = 1;
    for (int i = 1; i <= N; ++i) count *= i;
    cout << setprecision(15) << fixed;
    cout << res / count << endl;
    return 0;
}