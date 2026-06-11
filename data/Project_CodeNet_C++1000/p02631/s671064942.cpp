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
	int n;
	cin >> n;

	vector<int> data(n);
	rep(i, n)
		cin >> data[i];

	int XOR = 0;

	rep(i, n)
		XOR ^= data[i];

	rep(i, n) {
		cout << (XOR ^ data[i])<<" ";
	}
	cout << endl;

	return 0;
}