#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	cin >> n;
  if (n&1) return puts("0"), 0;
    long long ans = 0;
    n /= 2;
    while (n > 0) {
        n /= 5;
        ans += n;
    }
    cout << ans << endl;
	return 0;
}
