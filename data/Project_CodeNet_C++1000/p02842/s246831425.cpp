#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = INF;
	cin >> n;
	int ans = 1;
	bool yes = false;
	for(int i =1;i<n+1;i++)  {	
		if(int(i*1.08) == n) { 
			ans = i;
			yes = true;
		}
	}
	if(yes)
		cout << ans << '\n';
	else
		cout << ":(\n";
}