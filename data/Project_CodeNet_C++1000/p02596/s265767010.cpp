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
	int k;
	cin >> k;

	int keta = 0;
	int number = 0;
	while (keta < k) {
		keta++;
		number = number * 10 + 7;
		if (number % k == 0) {
			cout << keta << endl;
			return 0;
		}
		number = number % k;
	}
	cout << -1 << endl;
	return 0;
}