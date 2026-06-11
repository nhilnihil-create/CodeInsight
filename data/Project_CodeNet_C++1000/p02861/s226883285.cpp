#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> visited(9);
vector<int> perm;
double sum = 0;
double cnt = 0;
vector<pair<double, double>> a(9);
void dfs () {
    if ((int) perm.size() == n) {
        cnt++;
        for (int i = 0; i < n - 1; i++) {
            int ii = perm[i];
            int jj = perm[i + 1];
            double dx = a[ii].first - a[jj].first;
            double dy = a[ii].second - a[jj].second;
            sum += pow(dx * dx + dy * dy, 0.5);
        }
    } else {
        for (int i = 0; i < n; i++) {
            if(visited[i]) continue;
            visited[i] = 1;
            perm.push_back(i);
            dfs();
            visited[i] = 0;
            perm.pop_back();
        }
    }
}
void solve () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    dfs();
    cout << fixed << setprecision(10) << sum / cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
