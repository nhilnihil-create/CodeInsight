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

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	a = a - b;
	c = c - a;
	if (c < 0) {
		c = 0;
	}
	cout << c;
	return 0;
}