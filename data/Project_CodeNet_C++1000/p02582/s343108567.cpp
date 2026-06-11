#include <iostream>
#include <string>
using namespace std;
string k;
int i, n, r ,s;
int main(){
	cin>>k;
	
	for(i=0; i<=2; i++){
		if(k[i]=='R') r++;
		else s++; 
	}
	if(k[1]=='S'){
		if(r==0) cout<<"0";
		else cout<<"1";
	}
	else cout<<r;
}