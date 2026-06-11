#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10],b[10],ans=0; 
void fun(int a[10],int b[10]){
	do{
		int flag=1;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				flag=0;
				ans++;
				break;
			}
		}
		if(flag) break;
	}while(next_permutation(a,a+n));
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++){
		if(a[i]<b[i]){
			fun(a,b);
			break;
		}
		else if(a[i]>b[i]){
			fun(b,a);
			break;
		}
	}
	cout<<ans;
	return 0;
}