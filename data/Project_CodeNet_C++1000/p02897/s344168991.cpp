#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    double n;
    cin >> n;

    int odd = (n + 1) / 2;

    cout << 1.0 * odd / n << '\n';
    return 0;
}
