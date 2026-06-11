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

int main()
{
//	cut here before submit 
//	freopen ("testcase.MV", "r", stdin );
	string str = "";
	map<int,int> cnt; cnt.clear();
	int max_cnt = 0;
	while (getline (cin, str ) ){
		stringstream ss (str );
		int a;
		ss >> a;
		cnt[a]++;
		max_cnt = max (max_cnt, cnt[a] );
	} // end while
	vector<int> res; res.clear();
	map<int,int>::iterator it = cnt.begin();
	for (;it != cnt.end(); it++ ){
		int num = (*it).first;
		int c = (*it).second;
		if (max_cnt == c ){
			res.push_back (num );
		} // end if
	} // end for
	sort (ALL (res ) );
	rep (i, res.size() ){
		cout << res[i] << endl;
	} // end rep
		
	return 0;
}