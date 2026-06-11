#include<bits/stdc++.h>
using namespace std;
int a[210];
int main(){
	int x,y;
	cin>>x>>y;
	a[1]=300000;a[2]=200000;a[3]=100000;
	if(x==1&&y==1){
		cout<<a[x]+a[y]+400000<<endl;
	}
	else  cout<<a[x]+a[y]<<endl;
}