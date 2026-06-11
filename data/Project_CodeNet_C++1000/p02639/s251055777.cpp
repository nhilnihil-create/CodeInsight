#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <type_traits>

#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == 0)
        {
            cout << i + 1 << endl;
        }
    }
}