// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
// Kahn's algorithm
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char **argv)
{
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> A(V);
        vector<int> B(V);
        for (int i = 0; i < E; i++) {
                int s, t;
                cin >> s >> t;
                A[s].push_back({t, 0});
                B[t]++;
        }
        int edges = E;
        vector<int> L;
        queue<int> S;
        for (int i = 0; i < V; i++)
                if (!B[i])
                        S.push(i);
        while (!S.empty()) {
                auto c = S.front();
                S.pop();
                L.push_back(c);
                for (auto &a: A[c]) {
                        if (a.second)
                                continue;
                        a.second = 1;
                        edges--;
                        if (--B[a.first] == 0)
                                S.push(a.first);
                }
        }
        for (int i = 0; i < V; i++)
                cout << L[i] << endl;
        return 0;
}