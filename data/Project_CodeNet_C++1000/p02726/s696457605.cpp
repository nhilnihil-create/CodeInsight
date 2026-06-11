#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    --X, --Y;
    vector<int> res(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int d = min({abs(i - j), abs(i - X) + abs(j - Y) + 1,
                         abs(i - Y) + abs(j - X) + 1});
            res[d]++;
        }
    }

    for (int d = 1; d < N; ++d) cout << res[d] << endl;

    return 0;
}
