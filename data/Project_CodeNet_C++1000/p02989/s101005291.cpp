#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> d;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		d.push_back(x);
	}
	sort(d.begin(), d.end());
	cout << d[n/2]-d[(n-1)/2] << endl;
	return 0;
}
