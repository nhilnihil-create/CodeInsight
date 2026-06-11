#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	long long n;
	cin >> n;

	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	cout << a.size() << endl;

	return 0;
}