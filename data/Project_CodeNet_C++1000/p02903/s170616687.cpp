#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

// 5 2 4 
// 111000
// 000111

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)



int main() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;

	rep(y,H) {
		rep(x,W) {
			if ((x < A && y < B) || (x >= A && y >=B)) {
				cout << 0;
			} else {
				cout << 1;
			}
		}
		cout << endl;
	}

	return 0;
}