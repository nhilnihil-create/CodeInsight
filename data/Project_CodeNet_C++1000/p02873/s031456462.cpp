#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int N = S.size() + 1;
	vector<int> A( N );
	vector<int> v;
	for( int i = 0; i < N - 1; i++ ) {
		if( i == 0 && S[i] == '<' ) {
			int j = i;
			int n = 0;
			while( j < N - 1 && S[j] == '<' ) {
				A[j] = n;
				n++;
				j++;
			}
			if( j < N ) A[j]  = max( A[j], n );
		}
		if( i == N - 2 && S[i] == '>' ) {
			int j = i;
			int n = 0;
			while( j >= 0 && S[j] == '>' ) {
				A[j + 1] = n;
				n++;
				j--;
			}
			if( j + 1 >= 0 ) A[j + 1] = max( A[j + 1], n );
		}
		else if( i + 1 < N - 1 && S[i] == '>' && S[i + 1] == '<' ) {
			int j = i;
			int n = 0;
			while( j >= 0 && S[j] == '>' ) {
				A[j + 1] = n;
				n++;
				j--;
			}
			if( j + 1 >= 0 ) A[j + 1] = max( A[j + 1], n );
			j = i + 1;
			n = 1;
			while( j < N - 1 && S[j] == '<' ) {
				A[j + 1] = n;
				n++;
				j++;
			}
			if( j + 1 < N ) A[j + 1]  = max( A[j + 1], n );
		}
	}
	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		ans += A[i];
	}

	cout << ans << endl;
}
