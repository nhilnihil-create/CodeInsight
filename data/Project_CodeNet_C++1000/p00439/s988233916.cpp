#define _USE_MATH_DEFINES
#include <iostream>
#include <memory>
#include <memory.h>
#include <fstream>
#include <cmath>
#include <math.h>
#include <numeric>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <map>
#include <iomanip>
#include <list>
#include <cctype>
#include <algorithm>
#include <complex>

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)
using namespace std;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double, double> Pd;
typedef pair<int, P> PP;
typedef pair<int, PP> PPP;
const int INF = 1 << 29;
const double EPS = 1E-10;

#define rep(i, n) for(int i = 0; i < n; i++)

int nums[200000];

int main(){
	int n, k;
	while(cin >> n >> k && (n || k)){
		int res = -INF;
		int sum = 0;
		rep(i, n){
			cin >> nums[i];
		}
		rep(i, k){
			sum += nums[i];
		}
		int r = k;
		int l = 0;
		while(r < n){
			sum += nums[r++] - nums[l++];
			res = max(res, sum);
		}
		cout << res << endl;
	}
	return 0;
}