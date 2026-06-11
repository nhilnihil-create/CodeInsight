#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int M=1e9+7;
int main(){
	
	string s;
	cin>>s;
	int ans=0;
	for(auto x:s){
		ans+=x-'0';
	}
	if(ans%9==0)cout<<"Yes";
	else cout<<"No";
	return 0;
}