#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L

#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;
   
int sum(int l, int r) {

	return (l + r)*(r - l + 1) / 2;

}

int32_t  main() {

	IOS;

	 
		int n, k;

		cin >> n >> k;

		int ans = 0;

		for (int i = k; i <= n+1; i++) {

			int l = sum(0, i - 1);

			int r = sum(n-i+1, n);

			ans += r - l + 1;

			ans %= 1000000007;
		}

		cout << ans << endl;
 

}
