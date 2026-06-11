#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,ans=0;
  cin>>N;
  string S;
  cin>>S;
  rep(i,N){
    if(S[i]=='A'&&S[i+1]=='B'&&S[i+2]=='C')ans+=1;
  }
  cout<<ans<<endl;
}