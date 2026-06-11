#include<bits/stdc++.h>
using namespace std;

int main(){
  string S; cin>>S;
  int ans=0;
  int l=S.length();
  if(l%2==1)l+=1;
  for(int i=0; i<l/2; i++){
    if(S[i]!=S[S.length()-i-1])ans++;
  }
  cout<<ans<<endl;
  return 0;
}
