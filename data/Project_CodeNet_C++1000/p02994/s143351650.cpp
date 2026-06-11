#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, l;
	cin >> n >> l;
	if (l <= 0 && 0 <= l + n - 1)cout << (l+l+n-1)*n/2 << endl;
	else if(l+n-1<0) cout << (l + l + n - 1) * n / 2 -(l+n-1)<< endl;
	else if (0 < l)cout << (l + l + n - 1) * n / 2 - l << endl;

	//l ~ l+n-1
}