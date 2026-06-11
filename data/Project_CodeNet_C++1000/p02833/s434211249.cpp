#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    long long n;
    cin >> n;
    if (n % 2 == 0) {
        n /= 2;
        long long fac = 5;
        long long count = 0;
        while (n / fac >= 1) {
            count += n / fac;
            fac *= 5;
        }
        cout << count << endl;
    } else {
        cout << 0 << endl;
    }
    

	return 0;
}