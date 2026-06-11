#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	int x, y, ans;
	ll K, num=0;

	cin >> x >> y;

	rep(i, x){
		if ((x * 4 >= y)&&(y>=x*2)){
			y = x * 4 - y;
			if (y % 2 == 0){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

	return 0;
}