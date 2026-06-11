#include<bits/stdc++.h>
using namespace std;
long long int n,a[1000001];
int gcd(int c,int d) {
	return d==0?c:gcd(d,c%d);
}
int main() {
	cin>>n;
	int ans=0;
	for (int i=0; i<n; i++) {
		int x;
		cin>>x;
		a[x]++;
		ans=gcd(ans,x);
	}
	int ok=1;
	for (int i=2; i<=1000000; i++) {
		int cnt=0;
		for (int j=i; j<=1000000; j+=i)
			cnt+=a[j];
		if (cnt>1) ok=0;
	}
	if (ok) cout<<"pairwise coprime"<<endl;
	else if (ans==1) cout<<"setwise coprime"<<endl;
	else cout<<"not coprime";

	return 0;
}