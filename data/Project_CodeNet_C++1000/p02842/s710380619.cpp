#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)



int main(){
	int n;
	cin >> n;
	bool p = 1;
	for (int i = 1; i <= n;i++) {
		if (n == i * 108 /100) {
			if (108 * i % 100 == 0) {
				cout << (int)100 * n / 108 << endl;
			}
			else cout << (int)100 * n / 108 + 1 << endl;
			p = 0;
			break;
		}
	}
	if (p == 1)cout << ":(" << endl;
	return 0;
}