#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	bool posible=false;
	int data[x+1];
	//data[0]=4*x;
	for(int i=0;i<=x;i++){
		data[i]=(4*(x-i)+(i*2));
	}
	for(int i=0;i<x+1;i++){
		if(data[i]==y)
		posible=true;
	}
	if(posible){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}