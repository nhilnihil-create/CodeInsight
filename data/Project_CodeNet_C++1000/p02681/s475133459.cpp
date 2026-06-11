#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s;
  string t;
  cin>>s>>t;

  if(t.erase(s.size(),1)==s){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  
  
return 0;
}
