#include <bits/stdc++.h>

using namespace std;

string solve(int A, int B)
{
    int dist = abs(A - B);

    if (dist % 2)
        return "IMPOSSIBLE";

    return to_string(min(A, B) + dist / 2);
}

int main()
{
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    auto ans = solve(A, B);

    cout << ans << '\n';

    return 0;
}
