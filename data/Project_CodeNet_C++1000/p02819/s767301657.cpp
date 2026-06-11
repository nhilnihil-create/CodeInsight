#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int p[200100];

void prime()
{
    rep(i, 200000) p[i] = 1;
    for (int i = 2; i < 200000; i++)
    {
        if (p[i] == 0)
            continue;
        for (int j = i + i; j < 200000; j += i)
        {
            p[j] = 0;
        }
    }
    return;
}

int main()
{
    prime();
    // rep(i, 100) if (p[i] == 1) cout << i << endl;
    int x;
    cin >> x;
    int ans = 0;
    for (int i = x; i < 200000; i++)
    {
        if (p[i] == 1)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}