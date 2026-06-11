#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int n, m;
string s;
int nxt[100005];

int main()
{
    cin >> n >> m >> s;
    int p = -1;
    for (int i = n; i >= 0; --i)
    {
        if (s[i] == '0')
            p = i;
        nxt[i] = p;
    }
    vector<int> sol;
    int x = n;
    while (x >= m)
    {
        sol.push_back(x - nxt[x - m]);
        if (x == nxt[x - m])
            return cout << -1, 0;
        x = nxt[x - m];
    }
    if (x > 0)
        sol.push_back(x);
    reverse(all(sol));
    for (int x : sol)
        cout << x << ' ';
}
