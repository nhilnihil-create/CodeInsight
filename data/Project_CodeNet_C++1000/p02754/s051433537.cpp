#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n, a, b;
    cin >> n >> a >> b;

    long long x = n / (a+b);
    long long y = (n % (a+b) > a)?a:(n % (a+b));
    long long ans = x * a + y;

    cout << ans << endl;
    return 0;
}
