#include <bits/stdc++.h>
using namespace std;

void solve(string S, string T)
{
    int res = 0;
    for (int i = 0; i < (int)S.size(); i++)
    {
        if (S.at(i) == T.at(i))
            res++;
    }
    cout << res << endl;
}

int main()
{
    string S;
    cin >> S;
    string T;
    cin >> T;
    solve(S, T);
    return 0;
}
