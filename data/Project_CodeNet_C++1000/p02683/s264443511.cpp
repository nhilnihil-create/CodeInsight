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
	int n, m, x;
	ll cost = 1e18;
	cin >> n >> m >> x;
	
	vector<vector<int>> book(n, vector<int>(m+1));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= m; j++)
			cin >> book[i][j];
	}
	
	for(int i = 1; i < (1 << n); i++) { //0001 / 0010 / 0011 / 0100 ...
		ll total = 0;
		vector<ll> val(m);
		
		for(int j = 0; j < n; j++) {
			if(i&(1<<j)) { // this if gets the binary and checks if it is a 1
				total += book[j][0];
				for(int k = 0; k < m; k++) 
					val[k] += book[j][k+1]; //first indice is for the cost +1
			}
		}
		
		bool flag = 1;
		for(int j = 0; j < m; j++) {
			flag &= val[j] >= x;
		}
		
		if(flag) cost = min(cost, total);
	}
	
	cout << ((cost == 1e18) ? -1 : cost) << endl;
	
	return 0;
}
