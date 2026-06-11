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
#include <map>
#include <numeric>
#include <functional>
using namespace std;
using ll = long long;
using ld = long double;
const int mxn = 1e5+10;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int r, g, b, k; cin>>r>>g>>b>>k;
	while(b<=r) {b*=2, k--; if(k<0) {cout << "No\n"; return 0;}}
	while(g<=r) {g*=2, k--; if(k<0) {cout << "No\n"; return 0;}}
	while(b<=g) {b*=2, k--; if(k<0) {cout << "No\n"; return 0;}}
	cout << "Yes\n";

	return 0;
}