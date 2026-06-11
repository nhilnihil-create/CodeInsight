#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int l;
    double d,ans;

    cin >> l;

    d = (double)l / 3.0;
    ans = d * d * d;

    std::cout << fixed << setprecision(12) << ans << endl;
}
