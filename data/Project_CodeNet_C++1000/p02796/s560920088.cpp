#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = n; i >= 0; --i)
#define P pair<int, int>
#define ALL(x) (x).begin(),(x).end()
const int INF = 1e9;
using namespace std;

const int MAX_N = 100000;

int main() {	
	int n, s[MAX_N], t[MAX_N];
	P tips[MAX_N];
	cin >> n;
	rep(i,n) cin >> s[i] >> t[i];
	rep(i,n) {
		tips[i] = P(s[i]+t[i], s[i]-t[i]);	
		}
	sort(tips, tips+n);
	
	int count=0, previousRobotArm=-INF;
	rep(i,n) {
		if(previousRobotArm <= tips[i].second) {
			count++;
			previousRobotArm = tips[i].first;
		}
	}
	cout << count << endl;
	}