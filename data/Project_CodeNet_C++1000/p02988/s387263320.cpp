#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> p(n+5);
	for (int i = 1; i <= n; i++) cin >> p[i];

	int ans = 0;
	for (int i = 2; i < n; i++)
		if (max({p[i-1],p[i],p[i+1]})!=p[i] && min({p[i-1],p[i],p[i+1]})!=p[i]) ans++;

	cout << ans << endl;
	return 0;
}