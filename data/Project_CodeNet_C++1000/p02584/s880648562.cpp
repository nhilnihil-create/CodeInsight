#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    long long x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    long long n = x / d;
    long long ans = x - min(k, n) * d;
    cout << (k <= n || (k - n) % 2 == 0 ? abs(ans): abs(ans - d)) << '\n';
    return 0;
}