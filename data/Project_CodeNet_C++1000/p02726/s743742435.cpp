//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//
//int main() {
//
//	int n, x, y;
//
//	cin >> n >> x >> y;
//
//
//	int ans[2005] = { 0 };
//
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			int min1 = min(abs(i - x), abs(i - y));
//			int min2 = min(abs(j - x), abs(j - y));
//			int min3 = min(abs(j - i),abs(min1 + 1 + min2));
//			ans[min3]++;
//		}
//
//
//	}
//
//	for (int i = 1; i < n; i++) {
//		cout << ans[i] << endl;
//	}
//}


#include<iostream>
#include<algorithm>

using namespace std;

int ans[2005];

int main() {

	int n, x, y;

	cin >> n >> x >> y;

	for (int i = 1; i < n ; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (j <= x) {
				ans[j - i]++;
			}
			else if (i >= y) {
				ans[j - i]++;
			}
			else {
				int a = min(j - i, abs(i - x) + 1 + abs(j - y));
				ans[a]++;
			}
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}