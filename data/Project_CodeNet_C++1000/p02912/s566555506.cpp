#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	priority_queue<long long> que;
	for( int i = 0; i < N; i++ ) {
		long long A;
		cin >> A;
		que.push( A );
	}

	for( int i = 0; i < M; i++ ) {
		long long A = que.top();
		que.pop();
		que.push( A / 2 );
	}
	long long ans = 0;
	while( !que.empty() ) {
		long long A = que.top();
		que.pop();
		ans += A;
	}

	cout << ans << endl;
}
