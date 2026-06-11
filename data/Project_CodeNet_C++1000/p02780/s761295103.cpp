#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<double> p( N );
	for( int i = 0; i < N; i++ )  {
		cin >> p[i];
	}

	vector<double> e( N );
	for( int i = 0; i < N; i++ )  {
		e[i] = p[i] * (p[i] + 1) / 2 / p[i];
	}
	vector<double> acc( N + 1 );
	for( int i = 0; i < N; i++ )  {
		acc[i + 1] = acc[i] + e[i];
	}
	double ans = 0;
	for( int i = 0; i <= N - K; i++ )  {
		ans = max( ans, acc[i + K] - acc[i] );
	}

	cout << fixed << setprecision(12) << ans << endl;
}
