#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parents;

public:
    UnionFind(int n) : parents(n)
    {
        for (int i = 0; i < n; i++)
        {
            parents.at(i) = -1;
        }
    }

    bool is_root(int x)
    {
        return parents.at(x) < 0;
    }

    int size(int x)
    {
        return -parents.at(find(x));
    }

    int find(int x)
    {
        if (is_root(x))
            return x;
        parents.at(x) = find(parents.at(x));
        return parents.at(x);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (size(x) < size(y))
            swap(x, y);
        parents.at(x) -= size(y);
        parents.at(y) = x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve(int N, int M, vector<int> A, vector<int> B)
{
    UnionFind tree = UnionFind(N);
    for (int i = 0; i < M; i++)
    {
        tree.unite(A.at(i), B.at(i));
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        res = max(res, tree.size(i));
    }
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> A(M);
    vector<int> B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> A.at(i);
        cin >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    solve(N, M, move(A), move(B));
    return 0;
}
