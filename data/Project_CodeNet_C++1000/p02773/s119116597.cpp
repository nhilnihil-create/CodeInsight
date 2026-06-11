#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; cin >> n;
    map<string, int> memo;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        memo[s]++;
    }

    int best = 0;
    for (auto x:memo)
        best = max(best, x.second);
    for (auto it = memo.begin(); it != memo.end(); it++)
    {
        if (it->second == best)
            cout << it->first << endl;
    }
}