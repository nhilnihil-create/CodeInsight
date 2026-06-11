#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  int N=S.size();
  bool ans=true;
  for(int i=0;i<N/2;i++) if(S.at(i)!=S.at(N-1-i)){
    ans=false;
    break;
  }
  for(int i=0;i<N/4;i++) if(S.at(i)!=S.at(N/2-i-1)) ans=false;
  for(int i=0;i<N/4;i++) if(S.at(N/2+1+i)!=S.at(N-1-i)) ans=false;
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
  
