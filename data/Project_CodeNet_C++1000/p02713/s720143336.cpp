#include <bits/stdc++.h>
#define rep(i,n) for (int i = 1; i<=(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main () {
    int n;
	cin >> n;

    ll sum = 0;

    rep(i,n)rep(j,n)rep(k,n) sum += gcd(i, gcd(j,k));

	cout << sum << endl;
	return 0;
}