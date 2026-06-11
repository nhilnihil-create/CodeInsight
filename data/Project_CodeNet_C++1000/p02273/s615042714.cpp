#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#include <complex>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef complex<double> P;

vector<P> pos;
double theta;

double move (double len )
{
	P p = pos.back();

	P q = p + len*exp (complex<double> (.0, theta*M_PI/180. ) );
	pos.push_back (q); 
}

void koch (int n, double len )
{
	if (n == 0 ){
		move (len );
	}else{
		koch (n-1, len );
		theta += 60.;
		koch (n-1, len );
		theta -= 120.;
		koch (n-1, len );
		theta += 60.;
		koch (n-1, len );
	} // end if		
}
int main()
{
	pos.clear();

	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	P p1 = P(0., 0. );
	P p2 = P(100., 0. );
	double len = abs (p2 - p1)/pow(3., n);

	theta = 0.;
	pos.push_back (p1 );

	koch (n, len );

	rep (i, pos.size() ) printf ("%.8lf %.8lf\n", pos[i].real(), pos[i].imag() );

	return 0;
}