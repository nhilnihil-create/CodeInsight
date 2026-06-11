#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	long long K;
	cin >> N >> K;
	vector<int> P( N );
	for( int i = 0; i < N; i++ ) {
		int p;
		cin >> p;
		p--;
		P[i] = p;
	}
	vector<long long> C( N );
	for( int i = 0; i < N; i++ ) {
		cin >> C[i];
	}

	long long ans = INT64_MIN;
	set<int> st;
	for( int j = 0; j < N; j++ ) {
		if( st.count( j ) ) continue;
		vector<int> vi;
		int now = j;
		long long sum = 0;
		set<int> st1;
		for( int i = 0; i < N * 2; i++ ) {
			if( st1.count( now ) ) {
				st.insert( st1.begin(), st1.end() );
				break;
			}
			st1.insert( now );
			now = P[now];
			sum += C[now];
			vi.push_back( now );
		}
		int n = vi.size();
		long long ma = 0;
		long long k = K;
		if( k / n > 1 ) {
			if( sum > 0 ) ma += sum * (k / n - 1);
			k -= (k / n - 1) * n;
		}
		for( int j = 0; j < n; j++ ) {
			long long aa = 0;
			for( int l = 0; l < k; l++ ) {
				aa += C[ vi[(j + l) % n] ];
				ans = max( ans, ma + aa );
			}
		}
	}

	cout << ans << endl;
}
