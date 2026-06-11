#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	map<int, int> mp;
	for( int i = 0; i < N; i++ ) {
		mp[ A[i] ]++;
	}
	long long all = 0;
	for( auto it = mp.begin(); it != mp.end(); it++ ) {
		long long n = it->second;
		all += n * (n - 1) / 2;
	}

	for( int i = 0; i < N; i++ ) {
		long long ans = all;
		long long n = mp[ A[i] ];
		ans -= n * (n - 1) / 2;
		n--;
		ans += n * (n - 1) / 2;
		cout << ans << endl;
	}
}
