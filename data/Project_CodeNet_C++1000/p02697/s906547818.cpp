#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,n;
int main(){
	cin>>a>>b;
	a=b*2+1;
	int m=b;
	if(b%2==1){
		int l=1,r=m;
		while(l!=r){
			printf("%d %d\n",l,r);
			l++;r--;
		}
		l=m+1,r=m*2+1;
		while(l<=r){
			printf("%d %d\n",l,r);
			l++;r--;
		}
	}
	if(b%2==0){
		int l=1,r=m+1;
		while(l!=r){
			printf("%d %d\n",l,r);
			l++;r--;
		}
		l=m+2,r=m*2+1;
		while(l<=r){
			printf("%d %d\n",l,r);
			l++;r--;
		}
	}
}