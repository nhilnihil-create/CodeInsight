#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    rep(i, N + 100)
    {
        if (i * 108 / 100 == N)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}