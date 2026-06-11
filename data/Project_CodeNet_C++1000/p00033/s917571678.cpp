#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;


int a[10];

bool put(int cur,int lt, int rt) {
	if (cur == 10)
		return true;
	if (a[cur] < lt && a[cur] < rt)
		return false;
	bool lres= false,rres=false;
	if( a[cur] > lt) {
		lres = put(cur + 1, a[cur], rt);
	}
	if( a[cur] > rt) {
		rres = put(cur + 1, lt, a[cur]);
	}
	if (lres || rres)
		return true;
	else
		return false;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 10; i++) {
			cin >> a[i];
		}
		if (put(0, 0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}