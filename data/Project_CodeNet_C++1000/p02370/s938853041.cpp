// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
// DFS algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>> &A, vector<bool> &U, vector<int> &R, int c)
{
        if (U[c])
                return -1;
        if (R[c])
                return R[c];
        U[c] = true;
        int m = 0;
        for (auto a: A[c]) {
                int d = dfs(A, U, R, a);
                if (d < 0) {
                        m = -2;
                        break;
                }
                m = max(m, d);
        }
        U[c] = false;
        R[c] = ++m;
        return m;
}

int main(int argc, char **argv)
{
        int V, E;
        cin >> V >> E;
        vector<vector<int>> A(V);
        for (int i = 0; i < E; i++) {
                int s, t;
                cin >> s >> t;
                A[s].push_back(t);
        }
        bool cyc = false;
        vector<bool> U(V);
        vector<int> R(V);
        for (int i = 0; i < V; i++) {
                if (!R[i] && dfs(A, U, R, i) < 0) {
                        cyc = true;
                        break;
                }
        }
        if (cyc) {
                cout << "Found cyclic path" << endl;
                return 0;
        }
        vector<int> P(V);
        iota(P.begin(), P.end(), 0);
        sort(P.begin(), P.end(), [&](int x, int y) { return R[x] > R[y]; });
        for (auto p: P)
                cout << p << endl;
        return 0;
}