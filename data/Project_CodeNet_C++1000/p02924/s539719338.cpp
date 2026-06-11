#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    sum = n * (n - 1) / 2;
    cout << sum << endl;
}