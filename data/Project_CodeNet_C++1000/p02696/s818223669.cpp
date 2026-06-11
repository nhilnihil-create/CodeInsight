#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long a, b, n;
    cin >> a >> b >> n;

    long long x;
    if (b > n) x = n;
    else x = b - 1;

    long long ans = floor((double)(a*x)/b);
    cout << ans << endl;
    return 0;
}
