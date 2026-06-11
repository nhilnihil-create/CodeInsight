#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }

int main()
{
    int k;
    int g,ans;

    cin >> k;

    ans = 0;
    for (int a = 1;a <= k;++a) {
        for (int b = 1;b <= k;++b) {
            for (int c = 1;c <= k;++c) {
                g = gcd(a, b);
                g = gcd(g, c);
                ans += g;
            }
        }
    }

    std::cout << ans << endl;

    return(0);
}
