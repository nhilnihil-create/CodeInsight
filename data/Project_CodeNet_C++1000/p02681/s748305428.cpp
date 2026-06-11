#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;

    bool yes = false;
    if (S.size() + 1 == T.size())
    {
        if (S == T.substr(0, S.size()))
        {
            yes = true;
        }
    }
    if (yes)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}