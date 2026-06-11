#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> l(n+10);

	for (int i=1; i<=n; i++) cin >> l[i];

	int d = 0;
	int ans = 1;

	for (int i=2; i<=n+1; i++){
		d += l[i-1];
		if (d <= x) ans += 1;
		else break;
	}
	cout << ans << endl;
	return 0;
}