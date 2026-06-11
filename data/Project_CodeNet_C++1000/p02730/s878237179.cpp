#include <bits/stdc++.h>
using namespace std;

int main(){
 string s;
  cin>>s;
  int n=s.size();
  bool a=true,b=true,c=true;
  for(int i=0;i<n;i++){
  	if(s[i]!=s[n-1-i]){
    	a=false;
    }
  }
  for(int i=0;i<(n-1)/2;i++){
  	if(s[i]!=s[(n-1)/2-1-i]){
    	b=false;
    }
  }
  for(int i=(n+3)/2-1;i<n;i++){
  	if(s[i]!=s[n-i+(n+3)/2-2]){
    	b=false;
    }
  }  
  if(a&&b&&c) cout<<"Yes";
  else cout<<"No";
 
}
