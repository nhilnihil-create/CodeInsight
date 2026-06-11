#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

void solve(int N, int Q, vector<int> t, vector<int> u, vector<int> v)
{
    dsu d(N);
    for (int i = 0; i < Q; i++)
    {
        if (t.at(i) == 0)
        {
            d.merge(u.at(i), v.at(i));
        }
        else
        {
            cout << ((d.same(u.at(i), v.at(i))) ? 1 : 0) << endl;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<int> t(Q);
    vector<int> u(Q);
    vector<int> v(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> t.at(i);
        cin >> u.at(i);
        cin >> v.at(i);
    }
    solve(N, Q, move(t), move(u), move(v));
    return 0;
}
