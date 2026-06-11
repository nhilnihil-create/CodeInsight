#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int m;
	cin >> m;

	ll digsum = 0;
	ll csum = 0;
	rep(i, m){
		ll d, c;
		cin >> d >> c;

		digsum += d * c;
		csum += c;
	}

	cout << (digsum-1) / 9 + csum - 1 << endl;
}
