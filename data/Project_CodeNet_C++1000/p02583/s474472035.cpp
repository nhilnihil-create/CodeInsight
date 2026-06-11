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
	int n, answer = 0;
	cin >> n;
	
	vector<int> v(n);
	FOR(i,n) cin >> v[i];
	
	for(int i = 2; i < n; i++) {
		for(int j = 1; j < i; j++) {
			for(int k = 0; k < j; k++) {
				int a = v[i], b = v[j], c = v[k];
				
				if(a != b && a != c && b != c)
					if(a + b > c && a + c > b && b + c > a) answer++;
			}
		}
	}
	
	cout << answer << endl;
	
	return 0;
}
