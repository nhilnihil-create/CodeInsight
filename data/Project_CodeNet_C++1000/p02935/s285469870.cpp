#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin >> n;
	vector<int> ing;
	for(i=0; i<n; i++){
		int x;
		cin >> x;
		ing.push_back(x);
	}
	sort(ing.begin(), ing.end());
	double res = ing[0];
	for(i=1; i<n; i++){
		res = (res+ing[i])/2.0;
		//cout << res << endl;
	}
	cout << res << endl;
	return 0;
}
