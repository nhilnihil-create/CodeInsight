#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	pair<long long, long long> task[n];
	for (int i = 0; i < n; i++)
	{
		cin >> task[i].second >> task[i].first;
	}
	sort(task, task + n);

	bool res = true;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += task[i].second;
		if(sum > task[i].first) res = false;
	}
	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
