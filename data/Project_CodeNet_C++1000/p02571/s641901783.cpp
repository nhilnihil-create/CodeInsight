#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(int)(n);i++)
using namespace std;



int main() {
 
  string s,t;
  cin>>s>>t;
  int i=0;
  int c=0;
  int j=0;
  int ans=10000;
  int tmp=0;
  while(true){
    
    if(i>s.length())break;
    if(j>=t.length()){
      if(tmp<ans)ans=tmp;
      tmp=0;
      j=0;
      c+=1;
      i=c;
      continue;
    }
    if(s[i]!=t[j])tmp+=1;
    j+=1;i+=1;
  }
  cout<<ans<<endl;
  return 0;
}

