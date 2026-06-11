#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<map>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;

int n,a[10],b[10],ans=0; 

void F(int a[],int b[]){
	do{
		int flag=1;
//		cout<<a[0]<<a[1]<<a[2]<<endl;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				flag=0;ans++;
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
			F(a,b);
			break;
		}
		else if(a[i]>b[i]){
			F(b,a);
			break;
		}
	}
	cout<<ans;
	return 0;
}