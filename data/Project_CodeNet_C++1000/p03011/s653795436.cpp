#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int P,Q,R;
  cin>>P>>Q>>R;
  int ans=P+Q+R-max(P,max(Q,R));
  
  cout<<ans<<endl;
  
}