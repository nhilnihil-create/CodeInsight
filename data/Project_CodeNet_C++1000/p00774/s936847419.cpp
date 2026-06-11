#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

int main() {
	for (int H; cin >> H&&H;) {
		int A[10][6] = {};
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> A[i][j];
			}
		}

		int ans = 0;

		for (bool flag = true; flag;) {//??????????????£???????????????
			flag = false;
			for (int i = 0; i < H; i++) {
				int F = 0, E = 1;
				for (int j = 1; j < 5 + 1; j++) {
					if (A[i][j] != A[i][j - 1]) {
						if (E - F >= 3) {
							flag = true;
							ans += A[i][j - 1] * (E - F);
							for (int f = F; f < E; f++) {
								A[i][f] = 0;
							}
							break;
						}
						F = j;
						E = j + 1;
					}
					else if (A[i][j - 1] != 0) {
						E++;
					}
				}
			}

			//cout << "before" << endl;
			//for (int i = 0; i < H; i++) {
			//	for (int j = 0; j < 5; j++) {
			//		cout << A[i][j] << " ";
			//	}
			//	cout << endl;
			//}

			for (bool flag2 = true; flag2;) {
				flag2 = false;
				for (int i = H - 1; i > 0; i--) { //i!=0
					for (int j = 0; j < 5; j++) {
						//?¶???????????????????
						if (A[i][j] == 0) {
							if (A[i - 1][j] |= 0)flag2 = true;
							swap(A[i][j], A[i - 1][j]);
						}
					}
				}
			}

			//cout << "after" << endl;
			//for (int i = 0; i < H; i++) {
			//	for (int j = 0; j < 5; j++) {
			//		cout << A[i][j] << " ";
			//	}
			//	cout << endl;
			//}
		}
		cout << ans << endl;
	}
	return 0;
}