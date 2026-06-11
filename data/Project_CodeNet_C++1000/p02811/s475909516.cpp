#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int k, x;
    cin >> k >> x;

    cout << (k * 500 >= x ? "Yes" : "No") << '\n';
    return 0;
}
