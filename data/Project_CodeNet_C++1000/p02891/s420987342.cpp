#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  int K;
  cin>>S>>K;
  char C=S[0];
  bool b=true;
  for(char c:S)
    if(c!=C){
      b=false;
      break;
    }
  if(b){
    cout<<S.size()*K/2<<endl;
    return 0;
  }
  int j=1,ans1=0,k;
  bool bo=true;
  for(int i=1;i<S.size();i++){
    if(S[i]!=S[i-1]){
      if(bo){
        k=j;
        bo=false;
      }
      else
        ans1+=j/2;
      j=1;
    }else
      j++;
  }
  if(S[0]!=S[S.size()-1])
    cout<<(k/2+ans1+j/2)*K<<endl;
  else
    cout<<ans1*K+(k+j)/2*(K-1)+k/2+j/2<<endl;
}