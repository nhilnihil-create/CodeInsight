#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;

using namespace std;

int c(int i, int k) {

	if (i == k || k == 0) 
		return 1;
	
	return c(i - 1, k - 1) + c(i - 1, k);
}

int main() {

	int n, m;
	cin >> n >> m;

	int ans = 0;

	if (n >= 2) {
		ans += c(n,  2);
	}
	
	if (m >= 2)
		ans += c(m,  2);

	cout << ans << endl;

}