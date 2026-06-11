#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int main(){
	scanf("%d",&n);
	int p=1;
	while (p<n)p<<=1;
	if (p==n){
		puts("No");
		return 0;
	}
	puts("Yes");
	p>>=1;
	if (n%4==3){
		for (int i=2;i<=2*n;i++)printf("%d %d\n",i-1,i);
		return 0;
	}
	if (n%4==1){
		for (int i=3;i<=n;i++)printf("%d %d\n",i-1,i);
		printf("%d %d\n",n,n+2);
		for (int i=3;i<=n;i++)printf("%d %d\n",i-1+n,i+n);
		printf("%d %d\n",1,2);
		printf("%d %d\n",3,n+1);
	}
	if (n%4==0){
		for (int i=1;i<n;i++)a[i]=i;
		swap(a[p],a[n-p-1]);
		for (int i=2;i<n;i++)printf("%d %d\n",a[i-1],a[i]);
		printf("%d %d\n",a[n-1],a[1]+n);
		for (int i=2;i<n;i++)printf("%d %d\n",a[i-1]+n,a[i]+n);
		printf("%d %d\n",n,p);
		printf("%d %d\n",2*n,n-p);
	}
	if (n%4==2){
		for (int i=2;i<=n-1;i++)a[i]=i;
		swap(a[p-1],a[n^p]);
		if ((n^p)==2&&n!=6)swap(a[p-2],a[3]);
		for (int i=2;i<=n-2;i++)printf("%d %d\n",a[i],a[i+1]);
		printf("%d %d\n",a[n-1],n+a[2]);
		for (int i=2;i<=n-2;i++)printf("%d %d\n",n+a[i],n+a[i+1]);
		printf("%d %d\n",n,p);
		printf("%d %d\n",2*n,n^p);
		printf("%d %d\n",1,2);
		printf("%d %d\n",1+n,3);		
	}
	return 0;
}