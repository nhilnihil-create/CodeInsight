#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

string solve(int M, const vector<int>& xs)
{
    int total = accumulate(xs.begin(), xs.end(), 0), ans = 0;

    for (int x : xs)
        if (x * 4 * M >= total)
            ++ans;

    return ans >= M ? "Yes" : "No";
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i];

    auto ans = solve(M, xs);

    cout << ans << '\n';

    return 0;
}
