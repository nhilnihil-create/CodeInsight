#include <bits/stdc++.h>

using namespace std;

string solve(int N, const vector<int>& xs)
{
    int off = 0;

    for (int i = 1; i <= N; ++i)
        off += (xs[i] != i ? 1 : 0);

    return off <= 2 ? "YES" : "NO";
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> ps(N + 1);

    for (int i = 1; i <= N; ++i)
        cin >> ps[i];

    auto ans = solve(N, ps);

    cout << ans << '\n';

    return 0;
}
