 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	int ans = 0;
	for( int n = 0; n < 1000; n++ ) {
		int n1 = n / 100;
		int n2 = n % 100 / 10;
		int n3 = n % 10;
		int state = 0;
		for( int i = 0; i < N; i++ ) {
			int num = S[i] - '0';
			if( state == 0 && num == n1 ) state++;
			else if( state == 1 && num == n2 ) state++;
			else if( state == 2 && num == n3 ) {
				state++;
				break;
			}
		}
		if( state == 3 ) ans++;
	}

	cout << ans << endl;
}
