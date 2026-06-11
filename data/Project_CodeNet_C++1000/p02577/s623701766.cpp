#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,s=0;
  string str;
	cin>>str;
	
	for(int i=0;i<str.size();i++){
		int j=str[i]-48;
		s+=j;
	}
	
//	s=0;
//	
//	while(n!=0){
//		s+=n%10;
//		n/=10;
//	}
//	
	if(s%9==0)
    cout<<"Yes";
    
    else cout<<"No";
    
	

}