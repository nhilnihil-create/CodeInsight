// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
// DFS algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<int>> &A, vector<int> &U, vector<int> &R, int c)
{
        if (U[c] == 2)
                return true;
        if (U[c] == 1)
                return false;
        U[c] = 1;
        for (auto a: A[c])
                if (!dfs(A, U, R, a))
                        return false;
        U[c] = 2;
        R.push_back(c);
        return true;
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
        vector<int> U(V), R;
        bool ok = true;
        for (int i = 0; i < V && ok; i++)
                if (!U[i])
                       ok = dfs(A, U, R, i);
        if (!ok) {
                cout << "Found cyclic path" << endl;
                return 0;
        }
        reverse(R.begin(), R.end());
        for (auto r: R)
                cout << r << endl;
        return 0;
}