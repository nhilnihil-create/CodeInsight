#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
using namespace std;
using ll = long long;
using ld = long double;
const int mxn = 22;
int a[mxn], b[mxn], c[mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans = 0;

	int n; cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];

	for(int i=0; i<n; i++) cin>>b[i];

	for(int i=0; i<n-1; i++) cin>>c[i];

	int prev = -1;
	for(int i=0; i<n; i++) {
		int d = a[i];
		ans+=b[d-1];
		if(d-1==prev) ans+=c[prev-1];
		prev = d;
	}

	cout << ans << '\n';


	
	return 0;
}