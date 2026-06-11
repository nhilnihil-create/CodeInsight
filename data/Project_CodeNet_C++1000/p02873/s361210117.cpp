#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;

    vector<int> A(S.size() + 1, 0);
    for (int i = 0; i < S.size(); i++)
    {
        if (S.at(i) == '<')
        {
            A.at(i + 1) = max(A.at(i + 1), A.at(i) + 1);
        }
    }

    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (S.at(i) == '>')
        {
            A.at(i) = max(A.at(i), A.at(i + 1) + 1);
        }
    }

    long ans = 0;
    rep(i, A.size())
    {
        ans += A.at(i);
    }

    cout << ans << endl;
    return 0;
}