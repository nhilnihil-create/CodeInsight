#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<bool> primes;
const int MAXV = 1e5;

int main()
{
    ll X;
    cin >> X;
    for (ll A = -200; A <= 200; A++) {
        for (ll B = -200; B <= 200; B++) {
            if (A*A*A*A*A - B*B*B*B*B == X) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
    return 0;
}
