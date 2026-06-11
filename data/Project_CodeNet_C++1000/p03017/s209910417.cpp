#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;
    int mxCD = max(C, D);
    for (int i = A; i < mxCD - 1; i++)
    {
        if (S[i] == '#' && S[i + 1] == '#')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if (C > D)
    {
        for (int i = B - 2; i < D - 1; i++)
        {
            if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.')
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}