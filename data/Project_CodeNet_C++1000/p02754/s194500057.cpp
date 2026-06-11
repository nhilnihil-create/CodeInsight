#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n, a, b; cin >> n >> a >> b;
    long long t = n / (a + b);
    long long s = n % (a + b);
    long long ans = a * t + min(s, a);
    cout << ans << endl;
}