#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <cmath>

#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main()
{
    int X, Y;
    cin >> X >> Y;
    rep(i, 0, X + 1)
    {
        if (i * 4 + (X - i) * 2 == Y)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}