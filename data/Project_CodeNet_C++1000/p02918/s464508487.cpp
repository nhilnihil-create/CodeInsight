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
const int mxn = 1e5+5;
char s[mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin>>n;
	int k; cin>>k;
	int block = 1;
	cin>>s;
	for(int i=1; i<n; i++) if(s[i]!=s[i-1]) block++;

	int ans = n-(block-2*k); 
	if(ans>=n) ans = n-1;
	cout << ans << '\n';

	
	return 0;
}