#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    string T;
    cin >> T;
    int t = T.size();

    rep(i, t)
    {
        if (T[i] == 'P')
        {
            if (i + 1 < t && T[i + 1] == '?')
                T[i + 1] = 'D';
        }
        else if (T[i] == '?')
        {
            if (i + 1 < t && T[i + 1] == 'D')
                T[i] = 'P';
            else
                T[i] = 'D';
        }
    }

    cout << T << endl;
}