#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,k;
	cin >> n >> k;
	double a[n];
	for(long long i=0;i<n;i++){
		cin >> a[i];
		a[i]=(a[i]+1.0)/2.0;
	}
	double b[n+1];
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i-1];
	}
	double ans=0.0;
	for(int i=0;i+k<=n;i++){
		ans=max(ans,b[i+k]-b[i]);
	}
	cout << fixed << setprecision(10);
	cout << ans << endl;
}
