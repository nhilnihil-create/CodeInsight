#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    double l;
    cin >> l;
    double x = l / 3;
    double ans = pow(x, 3);
    printf("%.12f\n", ans);
    return 0;
}