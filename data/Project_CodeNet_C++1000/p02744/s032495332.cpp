#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n;

void dfs(int max_c, string s)
{
    if(s.size() == n)
    {
        cout << s << endl;
        return;
    }
    rep(i, max_c)
    {
        dfs(max_c, s + (char)('a' + i));
    }
    dfs(max_c + 1, s + (char)('a' + max_c));
    return;
}

int main()
{
    cin >> n;
    dfs(1, "a");

    return 0;
}