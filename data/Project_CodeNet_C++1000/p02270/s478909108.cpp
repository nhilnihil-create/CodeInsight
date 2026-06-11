#include<iostream>
using namespace std;
#define MAX 100000
typedef long long llong;

int a, b;
llong M[MAX];

int confirmation(llong I) {
	int i = 0;
	for( int j=0; j<b; j++) {
		llong s = 0;
		while( s + M[i] <= I) {
			s += M[i];
			i++;
			if ( i==a ) return a;
		}
	}
	return i;
}

int workout() {
	llong left = 0;
	llong right = 100000 * 10000;
	llong mid;
	while (right - left > 1) {
		mid = (left + right) / 2;
		int v = confirmation(mid);
		if (v >= a) right = mid;
		else left = mid;
	}
	return right;
}

main() {
	cin >> a >> b;
	for ( int i = 0; i < a; i++) cin >> M[i];
	llong ans = workout();
	cout << ans << endl;
}

