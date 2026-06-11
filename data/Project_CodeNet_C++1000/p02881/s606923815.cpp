#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e6+10)


LL minx = 1ll << 60;
int main ()
{
	ios::sync_with_stdio(0);
	LL N;
	cin >> N;
	for ( LL i = 1 ; i*i <= N ; i++ )
		if ( N % i == 0 )
			minx = min ( minx , N/i + i - 2 );
	cout << minx << endl;

}