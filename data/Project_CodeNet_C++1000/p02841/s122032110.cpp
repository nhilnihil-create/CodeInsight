#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>

#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int m1, d1;
	cin >> m1 >> d1;
	int m2, d2;
	cin >> m2 >> d2;

	int ans = 0;
	if (m1 != m2) ans = 1;

	cout << ans << endl;

	return 0;
}
