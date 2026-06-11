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
int n, s;
int ans;
bool used[10];

void dfs (int curr, int curr_s, int pre )
{
	if (curr >= n ){
		if (curr_s == s ) ans++;
		return;
	} // end if

	for (int i = pre+1; i < 10; i++ ){
		if (!used[i] ){
			used[i] = true;
			dfs (curr+1, curr_s + i, i );
			used[i] = false;
		} // end if
	} // end rep
}

int main()
{
//	cut here before submit 
//	freopen ("testcase.Sum_of_Integers", "r", stdin );
	while (scanf ("%d %d", &n, &s ) ){
		if (n == 0 && s == 0 ) break;
		memset (used, false, sizeof (false ) );
		ans = 0;
		dfs (0, 0, -1 );
		printf ("%d\n", ans );
	} // end loop
		
	return 0;
}