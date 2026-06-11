#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;


int n,a[10],b[10],c[10],ans,cnt,Ans,flag,Flag;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	sort(c,c+n);
	cnt=1;
	do{
		flag=0;
		for(int i=0;i<n;i++){
			if(a[i]!=c[i]){
				flag=1;
				break;
			}
		}
		if(!flag){
			ans=cnt;
			break;
		}
		cnt++;
	}while(next_permutation(c,c+n));
	
	sort(c,c+n);
	cnt=1;
	
	do{
		Flag=0;
		for(int i=0;i<n;i++){
			if(b[i]!=c[i]){
				Flag=1;
				break;
			}
		}
		if(!Flag){
			Ans=cnt;
			break;
		}
		cnt++;
	}while(next_permutation(c,c+n));
	printf("%d",abs(Ans-ans));
	return 0;
} 