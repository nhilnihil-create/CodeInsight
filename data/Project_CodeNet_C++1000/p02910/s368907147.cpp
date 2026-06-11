#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	string s;
  	cin>>s;
  
  	bool ddr=true;
 	
  	rep(i,s.size()){
    	if(i%2==0&&s[i]=='L'){
        	ddr=false;
        }
      
      	if(i%2==1&&s[i]=='R'){
        	ddr=false;
        }
    }
  
  if(ddr){
  	cout<<"Yes"<<endl;
  }
  
  else{
  	cout<<"No"<<endl;
  }
}