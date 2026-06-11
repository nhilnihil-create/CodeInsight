#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c > 21)
        cout << "bust" << endl;
    else
        cout << "win" << endl;
}