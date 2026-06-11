#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {
    int n;
    cin >> n;

    static int divisors[1 << 24];
    for (int i = 1; i < 1 << 24; ++i) {
        for (int j = 1; i*j <=n; ++j) {
            divisors[i*j] += 1;
        }
    }

    ll ans = 0;
    for(int i = 1; i < n+1; ++i) {
        ans += ll(i) * divisors[i];
    }

    cout << ans << endl;

    return 0;
}