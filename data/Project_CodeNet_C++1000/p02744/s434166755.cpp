#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int n;
void dfs(string str, char mx)
{
    if ((int)str.size() == n)
    {
        cout << str << '\n';
        return;
    }

    for (char c = 'a'; c <= mx + 1; c++)
    {
        string nex = str;
        nex += c;
        dfs(nex, max(mx, c));
    }
}

int main()
{
    cin >> n;
    dfs("", 'a' - 1);
    return 0;
}
