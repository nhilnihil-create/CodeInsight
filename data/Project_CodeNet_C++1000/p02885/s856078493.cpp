#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	if(a<=2*b){
		cout<<"0";
		return 0;
	}
	else cout<<a-2*b;
	return 0; 
} 