// https://atcoder.jp/contests/abc158/tasks/abc158_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = 0;
    ans += (n / (a + b)) * a;
    ans += min(a, (n % (a + b)));

    cout << ans << endl;
    return 0;
}
