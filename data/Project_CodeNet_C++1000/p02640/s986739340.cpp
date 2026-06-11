#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	int sum;
	rep(i, x+1) {
		sum = 2 * i + 4 * (x - i);
		if (sum == y) {
			cout << "Yes" << endl;
			return 0;
		}

	}
	cout << "No" << endl;
	return 0;
}