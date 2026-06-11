#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=1;i<=(n);i++)

int main(){
  int n,count=0;cin>>n;
  vector<int> a(n+1,0),x(n+1,0),ans(n+1,0);
  REP(i,n) cin>>a.at(i);

  for(int i=n;i>=1;i--){
    ans.at(i)=x.at(i)^a.at(i);
    if(ans.at(i)) count++;
    for(int j=1;j*j<=i;j++){
      if(!(i%j)){
        x.at(j)^=ans.at(i);
        if((j!=1)&&(j!=i/j)) x.at(i/j)^=ans.at(i);
      }
    }
  }

  cout<<count<<endl;
  REP(i,n) if(ans.at(i)) cout<<i<<" ";
}