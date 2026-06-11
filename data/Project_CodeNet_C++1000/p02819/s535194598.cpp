#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

bool isPrime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    int x;
    cin >> x;
    int ans = 0;
    for (int i = x;; i++)
    {
        if (isPrime(i))
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}