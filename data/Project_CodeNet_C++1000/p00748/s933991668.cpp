#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const int SIZE = 300;
const int N = 1000000;
int p[SIZE+1];
int dp1[N+1], dp2[N+1];

void make_pollock (void )
{
	for (int i = 0; i <= SIZE; i++ ){
		ll ans = (ll)i*(i+1LL)*(i+2LL)/6LL;
		p[i] = (int)ans;
	} // end for
}

void make_dp (void )
{
	dp1[0] = 0;
	for (int i = 1; i <= SIZE; i++ ){
		int m = p[i];
		for (int j = m; j <= N; j++ ){
			if (dp1[j] > dp1[j - m] + 1 ){
				dp1[j] = dp1[j - m] + 1;
			} // end if
		} // end for
	} // end for

	dp2[0] = 0;
	for (int i = 1; i <= SIZE; i++ ){
		if (p[i] % 2 == 0 ) continue;
		int m = p[i];
		for (int j = m; j <= N; j++ ){
			if (dp2[j] > dp2[j - m] + 1 ){
				dp2[j] = dp2[j - m] + 1;
			} // end if
		} // end for
	} // end for	
}
	
int main()
{
	memset (p, 0, sizeof (p ) );
	fill (dp1, dp1+N+1, INF );
	fill (dp2, dp2+N+1, INF );

	make_pollock();
	make_dp ();

	int n;
	while (cin >> n && n ){
		cout << dp1[n] << ' ' << dp2[n] << endl;
	} // end while
	
	return 0;
}