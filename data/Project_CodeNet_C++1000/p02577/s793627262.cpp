#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int sum=0;
	for(auto& i:s)sum+=i-'0';
	if(sum%9==0){
		cout<<"Yes";
	}
	else {
		cout<<"No";
	}
}