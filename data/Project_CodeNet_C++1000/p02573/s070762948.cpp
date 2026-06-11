#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;


struct UnionFind
{
    int n;
    vector<int> parent;
    vector<int> rank;
    UnionFind(int _n) :n(_n)
    {
        parent.assign(n, -1);
        rank.assign(n, 1);
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        else
            return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)
    {
        i = find(i);
        j = find(j);

        if (i == j) return;

        if (rank[i] == rank[j])
        {
            parent[j] = i;
            ++rank[i];
        }
        else
        {
            if (rank[i] < rank[j]) swap(i, j);
            parent[j] = i;
        }
    }

    bool is_same(int i, int j)
    {
        return find(i) == find(j);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    rep(i, 0, M) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        uf.unite(A, B);
    }

    vector<int> cnt(N, 0);
    rep(i, 0, N) ++cnt[uf.find(i)];
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
    return 0;
}
