#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int x;
    cin >> x;

    int d = 360;
    int rem;
    while (1) {
        rem = d % x;
        if (rem == 0) {
            cout << d / x << endl;
            return 0;
        }
        d += 360;
    }

    return 0;
}
