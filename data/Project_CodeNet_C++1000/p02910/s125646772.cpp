#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";

const string NO = "No";

void solve(string S)
{
    for (int i = 0; i < (int)S.size(); i++)
    {
        if ((i % 2 != 0 && S.at(i) == 'R') ||
            (i % 2 == 0 && S.at(i) == 'L'))
        {
            cout << NO << endl;
            return;
        }
    }
    cout << YES << endl;
}

int main()
{
    string S;
    cin >> S;
    solve(S);
    return 0;
}
