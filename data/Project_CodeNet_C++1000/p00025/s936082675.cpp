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
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void check (int a[], int b[], int & hit, int & blow )
{
	rep (i, 4 ){
		rep (j, 4 ){
			if (a[i] == b[j] ){
				if (i == j ) hit++;
				else blow++;
			} // end if
		} // end rep
	} // end rep
}

int main()
{
//	cut here before submit 
//	freopen ("testcase.HB", "r", stdin );

	int a[4],b[4];
	while (scanf ("%d%d%d%d", &a[0], &a[1], &a[2], &a[3] ) != EOF ){
		scanf ("%d%d%d%d", &b[0], &b[1], &b[2], &b[3] );
		int hit = 0, blow = 0;
		check (a, b, hit, blow );
		printf ("%d %d\n", hit, blow );
	} // end while
		
	return 0;
}