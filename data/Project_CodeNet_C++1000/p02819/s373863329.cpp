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

bool isPrime(ll x) {
	if(x <= 1) return false;
	
	for(long d = 2; d*d <= x; d++) 
		if(x%d == 0) return false;
	
	return true;	
}

int main() {
	ll x;
	cin >> x;
	
	while(true) {
		if(isPrime(x)) { cout << x << endl; break; }
		x++;
	}
	
	return 0;
}