#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
const int MOD = 1e9 + 7;
const int INF = 9e18;

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<unordered_map<int, int>> coordinate(N, unordered_map<int, int>());
    for (int i = 0; i < N; i++) for (int j = 0; j < N - 1; j++) {
        cin >> A[i][j];
        A[i][j]--;
        coordinate[i][A[i][j]] = j;
    }
    vector<vector<int>> match(N, vector<int>(N, -1));
    int count = 0;
    for (int j = 0; j < N - 1; j++) for (int i = 0; i < N; i++) {
        if (match[i][j] == -1) {
            match[i][j] = count;
            match[A[i][j]][coordinate[A[i][j]][i]] = count;
            ++count;
        }
    }
    vector<vector<int>> G(count, vector<int>());
    vector<int> check(count, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N - 1; j++) {
            G[match[i][j - 1]].push_back(match[i][j]);
            check[match[i][j]]++;
        }
    }
    queue<int> next;
    vector<int> ans(count, -1);
    for(int i = 0; i < count; i++) {
        if (check[i] == 0) {
            ans[i] = 1;
            next.push(i);
        }
    }
    while (!next.empty()) {
        int now = next.front();
        next.pop();
        for (int temp : G[now]) {
            ans[temp] = max(ans[temp], ans[now] + 1);
            check[temp]--;
            if (check[temp] == 0) {
                next.push(temp);
            } else if (check[temp] < 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    int date = 0;
    for (auto i : ans) {
        if (i == -1) {
            cout << -1 << endl;
            return 0;
        }
        date = max(date, i);
    }
    cout << date << endl;
}