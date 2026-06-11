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
	long long int h, w,ans,ans2=0;
	cin >> h >> w;
	/*if (h % 2 == 0) {
		ans = h / 2;
		ans2 = ans;
	}
	else {
		ans = h /2 +1;
		ans2 = h - ans;
	}
	if (w % 2 == 0) {
		ans *= w / 2;
		ans2 = ans;
	}
	else {
		ans *= w / 2+1;
		ans2 *= w -( w / 2 + 1);
	}

	cout << ans2+ans << endl;*/
	if (h ==1 || w == 1) {
		cout << 1 << endl;
		return 0;
	}

	if (h * w % 2 != 0) {
		cout << h * w / 2 + 1 << endl;
	}
	else {
		cout << h * w / 2 << endl;
	}
	return 0;
}