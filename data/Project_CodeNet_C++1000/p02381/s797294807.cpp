#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
int main()
{
	int n, i;
	double m, d, s;

	while( cin >> n )
	{
		if( 0 == n )
			break;

		d = 0;
		m = 0;
		for(i = 0; i < n; ++i){
			cin >> s;
			m += s;
			d += s*s;
		}
		m = m / n;
		d = sqrt( d/n - m*m );

		cout << fixed << setprecision(5) << d << "\n";
	}

	return 0;
}