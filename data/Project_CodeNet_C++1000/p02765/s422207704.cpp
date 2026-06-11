#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{

    int n, r;
    cin >> n >> r;

    cout << (n >= 10 ? r : r + 100 * (10 - n)) << '\n';
    return 0;
}
