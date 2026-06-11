#include<bits/stdc++.h>
using namespace std;
int n;
bool pan(int x){
	int s=1;
	while (s<x) s*=2;
	if (s==x) return 1; else return 0;
}
int main()
{
	scanf("%d",&n);
	if (pan(n)) printf("%s\n","No");
	else {
		printf("%s\n","Yes");
		for (int i=1;i<=(n-1)/2;i++) 
		 {
		 	printf("%d %d\n",1,1+i*2);
		 	printf("%d %d\n",1+i*2,i*2);
		 	printf("%d %d\n",1,n+i*2);
		 	printf("%d %d\n",n+i*2,n+i*2+1);
		 } 
		printf("%d %d\n",2,n+1);
		if (n%2==0) {
			for (int i=2;i<=n-1;i++) if ((n^1^i)>1&&(n^1^i)<=n-1&&(n^1^i)!=i) 
			{
				if (i%2==1) printf("%d %d\n",n,i); else printf("%d %d\n",n,n+i);
				if ((n^1^i)%2==1) printf("%d %d\n",n<<1,(n^1^i)); else printf("%d %d\n",n<<1,(n^1^i)+n);
				break;
			}
		} 
	}
}