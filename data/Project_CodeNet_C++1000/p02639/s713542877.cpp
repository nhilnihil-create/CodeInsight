#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	rep(i, 5) {
		int buf;
		cin >> buf;
		if (i + 1 != buf) {
			cout << i + 1;
		}
	}
	return 0;
}