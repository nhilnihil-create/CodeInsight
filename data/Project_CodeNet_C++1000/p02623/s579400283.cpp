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
    	ll n, m, k, ans = 0;
    	cin >> n >> m >> k;
    	
    	vector<ll> a(n+1); a[0] = 0;
    	vector<ll> b(m+1); b[0] = 0;
    	
    	for(ll i = 1; i <= n; i++) {
    		cin >> a[i];
    		a[i] += a[i-1];
    	}
    	
    	for(ll i = 1; i <= m; i++) {
    		cin >> b[i];
    		b[i] += b[i-1];
    	}
    	
    	for(ll i = 0, j = m; i <= n; i++) {
    		if(k - a[i] < 0) break;
    		while(a[i] + b[j] > k) j--;
    		
    		ans = max(ans, i + j);
    	}
    	
    	cout << ans << endl;
    	
    	return 0;
    }
