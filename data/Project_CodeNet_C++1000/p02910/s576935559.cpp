#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >>s;
  char t1[3]={'R','U','D'};
  char t2[3]={'L','U','D'};
  int p=0,q=0;
  for(int i=0;i<s.size();++i){
    for(int j=0;j<3;j++){
      
      if(i%2==0){
        if(s[i]==t1[j]) p++;
      }
      else{
        if(s[i]==t2[j]) q++;
      }
    }
  }
  if(p+q==s.size()) cout <<"Yes"<<endl;
  else cout <<"No"<<endl;
}
  
          
  