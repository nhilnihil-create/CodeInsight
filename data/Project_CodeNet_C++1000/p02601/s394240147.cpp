#include <bits/stdc++.h>
using namespace std;
int a,b,c,k;
int main(){
	cin>>a>>b>>c>>k;
	while(k!=0){
		if(a<b && b<c){
			cout<<"Yes";
			return 0;
	}
		if(a>=b){
			k--;b*=2;
		}
		else if(b>=c){
			k--;c*=2;
		}
		
	}
	if(a<b && b<c){
			cout<<"Yes";
			return 0;
	}
	cout<<"No";
	return 0;
} 