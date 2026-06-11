#include<bits/stdc++.h>

using namespace std;


int main(){
 
  string s;
  cin>>s;
  if(s.length() %2==1)
  {
    cout<<"No";
    return 0;
  }
  for(int i =0 ;i < s.length();i+=2){
    
    if(s[i]=='h' && s[i+1]=='i'){
      continue;
    }
    
    cout<<"No\n";
    return 0;
    
  }
  
cout<<"Yes";
  return 0;
}
