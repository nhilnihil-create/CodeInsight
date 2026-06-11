#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#include <iomanip>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 100000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
double PI = atan2(0, -1);
int main () {
    double a, b, x;
    cin >> a >> b >> x;
	x /= a;
	double alpha;
	if (2*x <= a*b) {
		alpha = atan2(b, 2*x/b);
	} else {
		alpha = atan2(2*(a*b- x)/a, a);
	}
	cout << fixed << setprecision(10) << alpha / PI * 180  << endl;
    return 0;
}