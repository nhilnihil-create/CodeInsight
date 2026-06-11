#include<bits/stdc++.h>
using namespace std;
int a[1000000]={0};
int main(){
	
	a[0]=1;
	a[1]=1;
	for(int i=2;i<=(int)sqrt(1000000);i++){
		if(a[i]==0){
		for(int j=2*i;j<1000000;j+=i){
			a[j]=1;
		}
	}
}
	int n;
	cin>>n;
	int i=n;
	while(a[i]!=0){
		i++;
		}
		cout<<i;
}
