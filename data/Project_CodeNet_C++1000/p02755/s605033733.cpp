 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int ans = -1;
	int X = 0;
	while( 1 ) {
		int a = X * 8 / 100;
		int b = X * 10 / 100;
		if( a == A && b == B ) {
			ans = X;
			break;
		}
		if( b > B ) break;
		X++;
	}

	cout << ans << endl;
}
