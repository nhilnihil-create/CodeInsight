#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    vector<int> X(N);
    rep(i, N) cin >> X.at(i);

    int ans = 0;
    int sum_x = 0;

    rep(i, N)
    {
        sum_x += X.at(i);
        ans += pow(X.at(i), 2);
    }

    int tmp = ans;
    for (int i = 0; i < 100; i++)
    {
        tmp -= 2 * sum_x - N * (2 * i + 1);
        ans = min(tmp, ans);
    }

    cout << ans << endl;
    return 0;
}