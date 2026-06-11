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
	string S;
	cin >> S;
	int N = S.size();
	vector<string> v;
	string cur = "R";
	for (int i = 1; i < N; ++i) {
		if (S[i-1] == 'L' && S[i] == 'R') {
			v.push_back(cur);
			cur = "R";
		} else {
			cur += S[i];
		}
	}
	v.push_back(cur);
	vector<int> ans;
	rep(i,v.size()) {
		string cr = v[i];
		int n = cr.size();
		int l = find(cr.begin(), cr.end(), 'L') - cr.begin();
		int r = l-1;
		int even_dist_away_from_L = l/2;
		int odd_dist_away_from_L = l/2 + (l%2);
		int even_dist_away_from_R = (n-1-r)/2;
		int odd_dist_away_from_R = (n-1-r)/2 + ((n-1-r)%2);
		vector<int> cur_res(n,0);
		cur_res[l] += even_dist_away_from_L + odd_dist_away_from_R;
		cur_res[r] += odd_dist_away_from_L + even_dist_away_from_R;
		rep(i,n) cout << cur_res[i] << " ";
	}
	cout << endl;
    return 0;
}