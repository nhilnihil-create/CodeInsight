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


int n, m, q, ans = 0;
int a[50], b[50], c[50], d[50];
vector<int> v;

int check() {
	int score = 0;
	for(int i = 0; i < q; i++)
		if(v[b[i]] - v[a[i]] == c[i]) score += d[i];
	
	return score;
}

void dfs(int i, int cur) { //i goes up to N, cur goes up to 10
	if(i >= n) {
		ans = max(ans, check()); 
		return;
	}
	
	for(int j = cur; j <= m; j++) {
			v.pb(j);
			dfs(i+1, j);
			v.pop_back();
	}
}

int main() {
	cin >> n >> m >> q;
	
	for(int i = 0; i < q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--; //this way indices start at 0
		b[i]--;
	}
	
	dfs(0, 1);
	
	cout << ans << endl;
	
	return 0;
}