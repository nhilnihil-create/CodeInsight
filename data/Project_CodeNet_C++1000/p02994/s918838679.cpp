#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int solve(int N, int L)
{
    vector<ii> xs(N);
    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        xs[i] = ii(abs(L + i), L + i);
        ans += L + i;
    }

    sort(xs.begin(),  xs.end());

    ans -= xs.begin()->second;
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    auto ans = solve(N, L);

    cout << ans << '\n';

    return 0;
}
