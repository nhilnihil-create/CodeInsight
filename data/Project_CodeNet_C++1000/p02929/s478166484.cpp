#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)

int main()
{
	int N;
	string S;
	cin >> N >> S;
	long long ans = 1;
	if( S[0] == 'W' ) {
		ans = 0;
	}
	else {
		int k = 1;
		for( int i = 1; i < S.size(); i++ ) {
			if( S[i] == 'B' ) {
				if( k % 2 ) {
					ans *= k;
					ans %= MOD;
					k--;
				}
				else {
					k++;
				}
			}
			else {
				if( k == 0 ) {
					ans = 0;
					break;
				}
				if( k % 2 ) {
					k++;
				}
				else {
					ans *= k;
					ans %= MOD;
					k--;
				}
			}
		}
		if( k ) ans = 0;
	}
	for( int i = N; i > 1; i-- ) {
		ans *= i;
		ans %= MOD;
	}

	cout << ans << endl;
}
