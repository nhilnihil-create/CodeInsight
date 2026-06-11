// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
// BFS algorithm
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char **argv)
{
        int V, E;
        cin >> V >> E;
        vector<vector<int>> A(V);
        vector<int> B(V);
        for (int i = 0; i < E; i++) {
                int s, t;
                cin >> s >> t;
                A[s].push_back(t);
                B[t]++;
        }
        vector<bool> U(V);
        vector<int> L;
        queue<int> S;
        for (int i = 0; i < V; i++) {
                if (B[i] || U[i])
                        continue;
                S.push(i);
                U[i] = true;
                while (!S.empty()) {
                        auto c = S.front();
                        S.pop();
                        L.push_back(c);
                        for (auto a: A[c]) {
                                if (--B[a] == 0 && !U[a]) {
                                        S.push(a);
                                        U[a] = true;
                                }
                        }
                }
        }
        for (auto l: L)
                cout << l << endl;
        return 0;
}