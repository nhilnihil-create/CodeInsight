//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include "bits/stdc++.h"

#define rep(i,n) for(long long (i)=0;(i)<(long long)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define int long long

#define PI (3.14159265358979323)
#define MOD (1000000007LL)
#define INF (1LL<<60LL)
#define MAX_N (100001)
#define MAX (1000000000000000000LL)
using namespace std;

signed main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	ans += n * (s[0] - '0') * 100;
	ans += n * (s[2] - '0') * 10;
	ans += n * (s[3] - '0') * 1;
	ans = ans / 100;
	cout << ans << endl;
}