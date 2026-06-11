#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;

void dfs(string s)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }
    int mx = 0;
    rep(i, s.size()) mx = max(mx, s[i] - 'a' + 1);
    for (int i = 0; i <= mx; i++)
    {
        string next = s;
        next += i + 'a';
        dfs(next);
    }
}

int main()
{
    cin >> n;
    dfs("a");
    return 0;
}