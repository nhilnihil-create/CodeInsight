#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct Node{
	int money;
	int a[15];
}book[15];
int b[15];
int main(){
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0;i<n;i++){
		cin>>book[i].money;
		for(int j=0;j<m;j++)cin>>book[i].a[j];
	}
	int arr=2e9;
	for(int i=0;i<(1<<n);i++){
		memset(b,0,sizeof b);
		int sum=0;
		for(int j=0;j<n;j++){
			if(i>>j&1){
				sum+=book[j].money;
				for(int k=0;k<m;k++) b[k]+=book[j].a[k];
			}
		}
		bool flag=1;
		for(int k=0;k<m;k++) {
			if(b[k]<x){
				flag=0;
				break;
			}
		}
		if(flag) arr=min(sum,arr);
	}
	if(arr==2e9)cout<<"-1";
	else cout<<arr;
}