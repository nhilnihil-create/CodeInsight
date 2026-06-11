#include<bits/stdc++.h>
using namespace std;

int a[1919810];

void P(int u,int v) {
	cout<<u<<' '<<v<<'\n';
}

int main() {
	int n,x=1;cin>>n;
	while(x<n) x<<=1;
	if(n==x) return puts("No"),0;
	x>>=1;
	puts("Yes");
	if(n%4==3) {
		for(int i=1;i<2*n;i++) P(i,i+1);
	}
	else if(n%4==1) {
		for(int i=2;i<n;i++) P(i,i+1),P(i+n,i+n+1);
		P(1,2);P(n,n+2);P(n+1,n+3);
	}
	else if(n%4==0) {
		for(int i=1;i<n;i++) a[i]=i;
		swap(a[x-1],a[n^x]);
		for(int i=1;i<=n-2;i++) P(a[i],a[i+1]),P(n+a[i],n+a[i+1]);
		P(a[n-1],n+a[1]);P(n,x);P(2*n,n^x);
	}
	else {
		for(int i=2;i<n;i++) a[i]=i;
		swap(a[x-1],a[n^x]);
		if((n^x)==2&&n!=6) swap(a[x-2],a[3]);
		for(int i=2;i<=n-2;i++) P(a[i],a[i+1]),P(n+a[i],n+a[i+1]);
		P(a[n-1],n+a[2]);P(n,x);P(2*n,n^x);P(1,2);P(n+1,3);
	}
	return 0;
}
