#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int n;

void dfs(string str, char c_max)
{
    if (str.size() == n)
    {
        cout << str << '\n';
        return;
    }

    for (char c = 'a'; c <= c_max + 1; c++)
    {
        dfs(str + c, max(c, c_max));
    }
}

int main()
{
    cin >> n;

    dfs("a", 'a');
    // cout << ans << '\n';
    return 0;
}
