 #include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long ans = 0;
	if( N % 2 == 0 ) {
		long long n = 10;
		while( N / n ) {
			ans += N / n;
			n *= 5;
		}
	}

	cout << ans << endl;
}
