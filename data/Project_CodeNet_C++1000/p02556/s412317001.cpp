#include <bits/stdc++.h>
using namespace std;
const int M=2e5 +10;
long long a[M],b[M],n;
int main(){
	cin >> n;
	for(long long i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		a[i]=x-y;b[i]=x+y;
	}
	sort(1+a,a+1+n); sort(b+1,b+n+1);
	long long ans = max(a[n]-a[1],b[n]-b[1]);
	cout<<ans<<'\n';
	return 0;
}