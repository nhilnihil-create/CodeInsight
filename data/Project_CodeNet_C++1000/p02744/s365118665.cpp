#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int n;
void dfs(string str)
{
    if ((int)str.size() == n)
    {
        cout << str << '\n';
        return;
    }
    int str_max = 0;
    if (str.size() >= 1)
    {
        rep(i, str.size())
        {
            str_max = max(str_max, str[i] - 'a');
        }
    }
    for (int i = 0; i <= str_max + 1; i++)
    {
        string nex = str;
        nex += ('a' + i);
        dfs(nex);
    }
}

int main()
{
    cin >> n;
    dfs("a");
    return 0;
}
