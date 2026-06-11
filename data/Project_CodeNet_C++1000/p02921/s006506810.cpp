#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	string s,t;
  	cin>>s>>t;
  
  	int seikai;
  
  	if(s[0]==t[0]){
    	seikai++;
    }
  	if(s[1]==t[1]){
    	seikai++;
    }
  
  	if(s[2]==t[2]){
    	seikai++;
    }  
  
  cout<<seikai<<endl;
  
}