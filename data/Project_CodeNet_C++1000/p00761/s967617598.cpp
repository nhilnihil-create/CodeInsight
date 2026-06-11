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

int stoi (string s ){
	stringstream ss (s );
	int res;
	ss >> res;
	return res;
}
string itos (int n ){
	stringstream ss;
	ss << n;

	return ss.str();
}

int main()
{
	ios_base::sync_with_stdio(0);
	string a; int l;
	while (cin >> a >> l ){
		if (a == "0" && l == 0 ) break;
		set<int> num; num.clear();
		map<int,int> pos; pos.clear();
		int na = stoi (a );
		num.insert (na );
		int i = 0;
		pos[na] = i;
		while (true ){
			while (a.length() < l ){
				a = '0' + a;
			} // end while
			sort (ALL (a ) );
			int mina = stoi (a );
			reverse (ALL (a ) );
			int maxa = stoi (a );
			int next = maxa - mina;
			++i;
			if (num.count (next ) ){
				cout << pos[next] << ' ' << next << ' ' << i - pos[next] << endl;
				break;
			}else{
				num.insert (next );
				pos[next] = i;
			} // end if
			a = itos (next );
		} // end while
	} // end while
		
	return 0;
}