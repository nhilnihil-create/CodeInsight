#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int a[n], b[n], c[n-1];
	for(int i = 0; i < n; i++) { cin >> a[i]; a[i]--; }
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += b[a[i]];
		if(i < n-1) {
			if(a[i] + 1 == a[i+1]) res += c[a[i]];
		}
	}
	cout << res << endl;
	return 0;
}
