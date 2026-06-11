#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int i = 0, j = 0, n,ans,ans2;
	cin >> n;
	if (12 >= n) {
		cout << n << endl;
		return 0;
	}
	ans = n * 100 / 108;
	ans2 = n * 100 % 108;
	if (n <100) {
		if (ans2 == 0) {
			cout << ans << endl;
			return 0;
		}
		if (ans2 * 10 / 108 ==0) {
			cout << ":(" << endl;
			return 0;
		}
		else {
			cout << ans + 1 << endl;
			return 0;
		}
		
	}
	
	if (ans2!=0) {
		if (ans2 * 10 / 108 ==0) {
			cout << ":("  << endl;
			return 0;
		}
		else{
			cout << ans + 1 << endl;
			return 0;
		}
		
	}
	else {
		
		cout << ans << endl;
	}
	return 0;
}