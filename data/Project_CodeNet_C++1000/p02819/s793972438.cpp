#include <bits/stdc++.h>
using namespace std;

int main()
{
	int X;
	cin >> X;

	auto IsPrime = []( int num )
	{
		if (num < 2) return false;
		else if (num == 2) return true;
		else if (num % 2 == 0) return false;
		for ( int i = 3; i * i <= num; i += 2 ) {
			if (num % i == 0) return false;
		}
		return true;
	};

	for( int x = X; ; x++ ) {
		if( IsPrime( x ) ) {
			cout << x << endl;
			break;
		}
	}
}
