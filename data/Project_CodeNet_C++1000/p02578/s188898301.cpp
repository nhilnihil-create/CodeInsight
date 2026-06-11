#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	long long maxx = 0;
	long long ans=0;
	long long x;
	for (int i=1; i<=n; i++) {
		cin>>x;
		if (x>=maxx) {
			maxx=x;
		} else {
			ans+=(maxx-x);
		}
	}
	cout<<ans<<"\n";
return 0;
}