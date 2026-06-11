#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  int ans=0;
  if(D==1){
    if(B==30||B==31||B==28)ans=1;
  }
  cout<<ans<<endl;
}