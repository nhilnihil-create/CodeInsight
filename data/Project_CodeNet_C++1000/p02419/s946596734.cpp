#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>

using namespace std;

int main(){

  string s; cin>>s;  
  string t="\""+s+"\"";
   
  int count=0;
   
  while(1){
    
    string w; cin>>w;
    
    bool flag1=true,flag2=true;
    
    for(int i=0; i<s.size(); ++i){
      if(w.size()!=s.size()){
        flag1=false; break;
        }
      char a,b;
      a=tolower(w[i]); b=tolower(s[i]);
      if(a!=b) flag1=false;
      }
      
    for(int i=0; i<t.size(); ++i){
       if(w.size()!=t.size()){
        flag2=false; break;
        }
      char a,b;
      a=tolower(w[i]); b=tolower(t[i]);
      if(a!=b) flag2=false;
      }
    
    if(flag1||flag2) count++;
    
    if(w=="END_OF_TEXT") break;
     }

     cout<<count<<endl;

}