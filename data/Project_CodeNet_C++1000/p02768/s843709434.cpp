#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define N 1000000007

ll power(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            ans *= x;
            ans %= N;
        }
        x *= x;
        x %= N;
        n >>= 1;
    }
    return ans;
}

ll comb(ll n, int a) {
    ll acc = 1;
    for (int i = 0; i < a; i++) {
        acc *= n - i;
        acc %= N;
    }
    ll div = 1;
    for (int i = 0; i < a; i++) {
        div *= i + 1;
        div %= N;
    }
    div = power(div, N - 2);
    return (acc * div) % N;
}

int main()
{
    ll n;
    int a, b;
    cin >> n >> a >> b;
    ll acc = power(2, n);
    acc += (N - comb(n, a));
    acc %= N;
    acc += (N - comb(n, b));
    acc %= N;
    cout << (acc - 1) % N << endl;
    return 0;
}