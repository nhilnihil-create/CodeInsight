#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int k;
    cin >> k;
    int l = 9 * k;
    if (k % 7 == 0)
        l /= 7;
    int resto, i;
    i = 1;
    resto = 10 % l;
    for (i = 2; i <= l && resto != 1; i++) {
        resto = (resto * 10) % l;
    }
    int resp = -1;
    if (resto == 1)
        resp = i - 1;
    cout << resp << endl;

	return 0;
}