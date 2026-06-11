#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i=0; i<n; i++) cin >> d[i];
	sort(d.begin(),d.end());
	
	int border = n/2;
	int ans = d[border] - d[border-1];
	cout << ans << endl;
	return 0;
}