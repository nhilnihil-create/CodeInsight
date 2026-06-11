#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    vector<int> xs(5);
    rep(i, 5) cin >> xs[i];

    rep(i, 5)
    {
        if (xs[i] == 0)
        {
            cout << (i + 1) << endl;
            break;
        }
    }

    return 0;
}