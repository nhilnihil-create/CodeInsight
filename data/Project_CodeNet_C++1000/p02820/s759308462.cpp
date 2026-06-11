#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K,R,S,P;
  string T;
  cin>>N>>K>>R>>S>>P>>T;
  map<char,int> A;
  A['r']=P;A['s']=R;A['p']=S;
  int ans=0;
  for(int i=0;i<N;i++){
    if(i<K || T[i]!=T[i-K])ans+=A[T[i]];
    else T[i]='a';
  }
  cout<<ans<<endl;
}