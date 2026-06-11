#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, a;
    cin >> h >> a;

    if (h % a != 0)
        h += a;
    cout << h / a << endl;
}