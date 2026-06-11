#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  int ans=0;
  cin>>S;
  int N=S.size()/2,size=S.size();
  rep(i,N){
    if(S[i]!=S[size-1-i])ans+=1;
  }
  cout<<ans<<endl;
  return 0;
}