#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string s,t;
  cin>>s;
  
  int ans=1;
  t+=s[0];
  for(int i=1;i<s.size();i++){
    if(i!=s.size()-1){
      if(t.size()==1){
      	if(s[i]==t[0]){
       	 t+=s[i+1];
        	ans++;
        	i++;
     	 }
     	 else{
       	 t=s[i];
       	 ans++;
      	}
  	  }
  	  else{
   	   t=s[i];
    	  ans++;
   	 }
    }
    else{
      if(t.size()==2||(t.size()==1&&t[0]!=s[i])){
        ans++;
      }
    }
  }
cout<<ans<<endl;
  
}