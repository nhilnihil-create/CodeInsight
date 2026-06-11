#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int X,ans=0;
  cin>>X;
  int Xnum=X/100;
  if(Xnum*100<=X&&X<=Xnum*105)ans=1;
  cout<<ans<<endl;
}