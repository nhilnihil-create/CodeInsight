#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];

	sort(data.begin(), data.end(),greater<int>());
	
	long sum = 0;
	if (n > 1)
		sum = data[0];

	for (int i = 2; i < n; i++)
		sum += data[i / 2];

	cout << sum << endl;
	return 0;
}