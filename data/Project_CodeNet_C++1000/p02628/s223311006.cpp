#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> data(n);
	rep(i, n)
		cin >> data[i];

	sort(data.begin(), data.end());

	int sum = 0;
	rep(i, k)
		sum += data[i];

	cout << sum << endl;
	return 0;
}