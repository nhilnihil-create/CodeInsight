#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,T;
  cin>>S>>T;
  int ans=T.size();
    for(int i=0;i<=S.size()-T.size();i++){
      int diff=0;
        for(int j=0;j<T.size();j++){
          if(T[j]!=S[i+j])
            diff++;
        }
      ans=min(ans,diff);
    }
  cout<<ans<<endl;
}