#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

int kai(int n) {
	int w = 1;
	for(int i=1;i<=n;i++){
		w = w * i;
	}
	return w;
}

int main(){
	long long int n,m, cnt = 1;
	long long int ans = 1;
	
	cin >> n;
	m = n;
	for (int i = 0; i < m; i++) {
		if (n == 1)break;
		n = n / 2;
		ans += 2*cnt;
		cnt = 2 * cnt;
	}
	cout << ans << endl;
	return 0;
}
