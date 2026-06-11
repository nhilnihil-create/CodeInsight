#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORa(i,a,b) for(int i = a; i < b; i++)
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define SORT(a,n) sort(begin(a), begin(a) + n)
#define VSORT(v) sort(v.begin(), v.end())
#define MAX 1000000
#define ll long long
#define LOW(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define UP(s) transform(s.begin(),s.end(),s.begin(),::toupper)

//-------------------------------------------------------//

int main() {
	unsigned ll m = 1;
	int n;
	bool flag1 = false, flag2 = false;
	cin >> n;
	
	vector<unsigned ll> v(n);
	FOR(i, n) cin >> v[i];
	
	FOR(i,n) {
		if(v[i] == 0) flag1 = true;
	}
	
	for(int i = 0; i < n && !flag1; i++) {
		if(v[i] <= 1000000000000000000/m) m *= v[i];
		else {
			flag2 = true;
			break;
		}
	}
	
	if(flag1) cout << "0" << endl;
	else if(flag2) cout << "-1" << endl;
	else cout << m << endl;
	
	return 0;
}

