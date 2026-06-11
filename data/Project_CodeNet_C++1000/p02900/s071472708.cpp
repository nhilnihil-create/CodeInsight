#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long A, B;
	cin >> A >> B;

	long long gcd = __gcd( A, B );
	set<long long> st;
	for( long long i = 2; i * i <= gcd; i++ ) {
			while( gcd % i == 0 ) {
				gcd /= i;
				if( st.count( i ) == 0 ) st.insert( i );
			}	}
	st.insert( 1 );
	if( gcd != 1 ) st.insert( gcd );
	long long ans = st.size();

	cout << ans << endl;
}
