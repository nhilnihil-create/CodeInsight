#include<bits/stdc++.h>
using namespace std;
int main() {
	long long l, r; cin >> l >> r;
	if(r - l + 1 >= 2019) {
		cout << "0" << endl;
		return 0;
	}
	set<long long> s;
	for (int i = l; i <= r; i++)
	{
		s.insert(i % 2019);
	}

	vector<long long> a;
	for (auto p : s)
	{
		a.push_back(p);
	}
	long long res = 10000;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i+1; j < a.size(); j++)
		{
			res = min(res, a[i] * a[j] % 2019);
		}
	}
	cout << res << endl;
	return 0;
}
