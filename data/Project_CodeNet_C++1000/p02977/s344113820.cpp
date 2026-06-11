#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int main(){
	cin>>n;
	if ((n&(-n))==n)cout<<"No"<<endl;
	else {
		cout<<"Yes"<<endl;
		printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
		for (int i=4;i<n;i+=2){
			printf("%d %d\n%d %d\n",n+1,i,i,i+1+n);
			printf("%d %d\n%d %d\n",n+1,i+1,i+1,i+n);
		}
		if (~n&1){
			int k=n&(-n);
			printf("%d %d\n%d %d\n",k^1,n,n^k,n+n);
		}
	}
} 