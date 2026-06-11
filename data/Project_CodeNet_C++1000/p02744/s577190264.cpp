#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

int N;

void dfs(string s, char mx)
{
    if (s.length() == N)
        cout << s << endl;
    else
    {
        for (char c = 'a'; c <= mx; c++)
        {
            if (c == mx)
                dfs(s + c, mx + 1);
            else
                dfs(s + c, mx);
        }
    }
}

void solve(void)
{
    cin >> N;
    dfs("", 'a');
}

int main(void)
{
    solve();
}
