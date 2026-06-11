#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000

int main(){
	string s;cin>>s;
	bool Bad=false;
	for(int i=0;i<3;i++){if(s[i]==s[i+1]){Bad=true;}}
	
	if(Bad){cout<<"Bad"<<endl;}
	else{cout<<"Good"<<endl;}
	
	return 0;
}