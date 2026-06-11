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
const int mxn = 110;
const int inf = 1e5+5;
int b[mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ans = 0;

	int n; cin>>n;
	for(int i=0; i<n-1; i++) cin>>b[i];
	b[n-1] = inf;

	ans+=b[0];
	for(int i=1; i<n; i++) ans+=min(b[i-1], b[i]);
	cout << ans << '\n';
	
	return 0;
}