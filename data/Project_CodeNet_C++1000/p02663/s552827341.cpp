#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int h1,m1,h2,m2,k;
	cin>>h1>>m1>>h2>>m2>>k;
	int x =(h2-h1)*60+ m2-m1;
	if(x-k>0){
		cout<<x-k<<"\n";
	}else{
		cout<<0<<"\n";
	}

 
	
	
	
	
	return 0;
}