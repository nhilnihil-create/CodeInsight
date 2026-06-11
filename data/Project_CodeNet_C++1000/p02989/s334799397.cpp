#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>d(n);
	for(int i=0;i<n;i++)
	{
		cin >> d.at(i);
	}
	sort(d.begin(),d.end());
	int d1=d.at((n/2)-1),d2=d.at(n/2),k=d2-d1;
	cout << k << endl;
	return 0;
}
