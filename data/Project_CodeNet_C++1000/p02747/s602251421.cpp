#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;cin>>S;
  bool b=true;
  if(S.size()%2==1)b=false;
  for (int i=0; i<S.size();i+=2){
    if(S.substr(i,2)!="hi"){
      b=false;
      break;
    }
  }
  if(b)puts("Yes");
  else puts("No");
}
