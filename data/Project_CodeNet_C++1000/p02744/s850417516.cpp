#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int dfs(int N,int k,string s){
  if(N==0) cout<<s<<endl;
  else{
    for(int i=0;i<=k;i++){
      int l=k;
      if(i==k) l++;
      if(i==0) dfs(N-1,l,s+'a');
      if(i==1) dfs(N-1,l,s+'b');
      if(i==2) dfs(N-1,l,s+'c');
      if(i==3) dfs(N-1,l,s+'d');
      if(i==4) dfs(N-1,l,s+'e');
      if(i==5) dfs(N-1,l,s+'f');
      if(i==6) dfs(N-1,l,s+'g');
      if(i==7) dfs(N-1,l,s+'h');
      if(i==8) dfs(N-1,l,s+'i');
      if(i==9) dfs(N-1,l,s+'j');
    }
  }
  return 0;
}
int main(){
  int N;
  cin>>N;
  string s="a";
  dfs(N-1,1,s);
  
  return 0;
}