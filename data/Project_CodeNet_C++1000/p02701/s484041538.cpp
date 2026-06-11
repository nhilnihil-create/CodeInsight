#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int count;

	cin >> n;

	count = n;

	vector<string> data(n);

	for (int i = 0; i < n; i++) 
		cin >> data.at(i);

	sort(data.begin(), data.end());

	for (int i = 0; i < n - 1; i++) {
		if (data.at(i) == data.at(i + 1))
			count--;
	}

	cout << count << endl;

}