#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bitset<35> sta;

int n;

int main(){
	cin>>n;
	if (n==(n&-n)){
		cout<<"No"<<endl;
		return 0;
	}
	printf("Yes\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",1,2,2,3,3,n+1,n+1,n+2,n+2,n+3);
	int x,y;
	for (int i=5;i<=n;i+=2){
		if ((n^1^(i-1))>=2) x=i-1,y=n^1^(i-1);
		if ((n^1^i)>=2) x=i,y=n^i^1;
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",i-1,i,i+n,i-1+n,i-1,n+1,i+n,n+1);
	}
	if (n%2==0){
		if ((x==2 || x%2==1)&&x!=3) x+=n;
		if ((y==2 || y%2==1)&&y!=3) y+=n;
		printf("%d %d\n%d %d\n",n,x,2*n,y);
	}
	return 0;
}