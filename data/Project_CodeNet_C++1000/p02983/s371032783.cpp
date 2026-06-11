#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = unsigned long long;

int main() {

	ll L, R;
	int num = 10003;

	cin >> L >> R;

	if (L<2019&&R>=2019){
		cout << "0" << endl;
		return 0;
	}
	for (ll i = L; i < R; i++) {
		for (ll j = i + 1; j <= R; j++) {
			if ((j * i) % 2019 == 0) {
				cout << "0" << endl;
				return 0;
			}
			if ((j * i) % 2019 < num)num = (j * i) % 2019;
		}
	}
	cout << num << endl;
	return 0;
}