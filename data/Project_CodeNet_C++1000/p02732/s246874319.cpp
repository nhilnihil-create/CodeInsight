#include<iostream>
#include<vector>

using namespace std;

int kazu[200005];

int main() {

	int n;

	cin >> n;


	int k;
	vector<int> a;
	for (int i = 0; i < n; i++) {

		cin >> k;
		a.push_back(k);
		kazu[k]++;
	}
	long long sum=0;
	for (int i = 1; i <= n; i++) {
		sum += (long long)kazu[i] * (kazu[i] - 1) / 2;
	}

	for (int i = 0; i < n; i++) {
		//int cnt = 0;
		long long sabun = kazu[a[i]] * (kazu[a[i]] - 1) / 2 - (kazu[a[i] ]- 1) * (kazu[a[i]] - 2) / 2;
		

		cout << sum-sabun << endl;
	}




	return 0;
}