#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N - 1));
    rep(i, 0, N) rep(j, 0, N - 1) {
        cin >> A[i][j];
        --A[i][j];
    }
    vector<vector<int>> pos(N, vector<int>(N, -1));
    rep(i, 0, N) rep(j, 0, N - 1) {
        pos[i][A[i][j]] = j;
    }
    vector<vector<int>> U(N, vector<int>(N - 1, -1));
    int num = 0;
    rep(i, 0, N) rep(j, 0, N - 1) {
        if (U[i][j] >= 0) {
            continue;
        }
        U[i][j] = U[A[i][j]][pos[A[i][j]][i]] = num++;
    }
    vector<vector<int>> graph(num);
    vector<int> cnt(num, 0);
    rep(i, 0, N) rep(j, 0, N - 2) {
        graph[U[i][j]].push_back(U[i][j + 1]);
        ++cnt[U[i][j + 1]];
    }
    queue<int> que;
    rep(i, 0, num) {
        if (!cnt[i]) {
            que.push(i);
        }
    }
    int ans = 0;
    while (!que.empty()) {
        ++ans;
        queue<int> buf;
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            for (auto& next_node : graph[node]) {
                --cnt[next_node];
                if (!cnt[next_node]) {
                    buf.push(next_node);
                }
            }
        }
        while (!buf.empty()) {
            que.push(buf.front());
            buf.pop();
        }
    }
    rep(i, 0, num) {
        if (cnt[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}