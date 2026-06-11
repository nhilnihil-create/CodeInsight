#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int m;
    cin >> m;
    ll digit = -1;
    ll sum = -1;
    rep(i, m)
    {
        ll d, c;
        cin >> d >> c;
        digit += c;
        sum += c * d;
    }

    cout << digit + sum / 9 << endl;
}