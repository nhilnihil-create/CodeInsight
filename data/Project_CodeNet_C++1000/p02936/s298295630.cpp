#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int idx, map<int, set<int>>& tree, const vector<int>& add, int add_sum, vector<int>& ans, vector<bool>& is_used)
{
    if(is_used[idx]) return;
    add_sum += add[idx];
    ans[idx] = add_sum;
    is_used[idx] = true;
    for(auto i : tree[idx])
    {
        if(is_used[i]) continue;
        dfs(i, tree, add, add_sum, ans, is_used);
    }
    add_sum -= add[idx];
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N-1), B(N-1);
    for(int i=0; i<N-1; i++)
    {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    vector<int> P(Q), X(Q);
    for(int i=0; i<Q; i++)
    {
        cin >> P[i] >> X[i];
        P[i]--;
    }

    map<int, set<int>> tree;
    for(int i=0; i<N-1; i++)
    {
        tree[A[i]].insert(B[i]);
        tree[B[i]].insert(A[i]);
    }
    vector<int> add(N, 0);
    for(int i=0; i<Q; i++)
    {
        add[P[i]] += X[i];
    }

    vector<int> ans(N);
    vector<bool> is_used(N, false);
    int add_sum = 0;
    dfs(0, tree, add, add_sum, ans, is_used);

    for(int i=0; i<N; i++)
    {
        cout << ans[i];
        if(i!=N-1) cout << ' ';
        else cout << '\n';
    }

    return 0;
}
