#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; 
	cin >> n;

	vector<int> v(n);
	for(int &e : v) 
		cin >> e;
	
	sort(v.begin(), v.end());

	long long ans = 0;	
	for(int j = 0;j < n;++j)
		for(int i = j+1;i < n;++i)
				ans += (lower_bound(v.begin(), v.end(), v[j] + v[i]) - v.begin()) - (i+1); 
	cout << ans;
}
