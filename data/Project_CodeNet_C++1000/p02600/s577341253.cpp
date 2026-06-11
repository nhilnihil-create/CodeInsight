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
	int x; cin>>x;
	if(x<=599) cout << 8 << '\n';
	else if(x<=799) cout << 7 << '\n';
	else if(x<=999) cout << 6 << '\n';
	else if(x<=1199) cout << 5 << '\n';
	else if(x<=1399) cout << 4 << '\n';
	else if(x<=1599) cout << 3 << '\n';
	else if(x<=1799) cout << 2<< '\n';
	else cout <<1 << '\n';

	return 0;
}