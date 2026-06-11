#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

bool odd_digit(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt & 1;
}

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    rep2(i, 1, n + 1)
    {
        if (odd_digit(i))
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return (0);
}
