#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[10]={1,2,3,4,5,6,7,8};
	int b[10]={1,2,3,4,5,6,7,8},c[10],d[10];
	int n,count1=0,count2=0,sum;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c[i]; 
	}
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	do{
		sum=0;
		for(int i=0;i<n;i++){
			if(a[i]==c[i]) sum++;
			else break;
		}count1++;
		if(sum==n) {
			break;
		}
	}while(next_permutation(a,a+n));
	do{
		sum=0;
		for(int i=0;i<n;i++){
			if(b[i]==d[i]) sum++;
			else break;
		}count2++;
		if(sum==n) {
			break;
		}
	}while(next_permutation(b,b+n));
	printf("%d\n",abs(count2-count1));
}