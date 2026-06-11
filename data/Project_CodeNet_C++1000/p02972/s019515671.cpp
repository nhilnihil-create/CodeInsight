#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=1;i<=(n);i++)

int main(){
  int n,c=0;cin>>n;
  vector<int> a(n+1,0),x(n+1,0);
  REP(i,n) cin>>a.at(i);

  for(int i=n;i>=1;i--){
    x.at(i)^=a.at(i);
    if(x.at(i)) c++;
    for(int j=1;j*j<=i;j++) if(!(i%j)){
      if(i!=1) x.at(j)^=x.at(i);
      if((j!=1)&&(j!=i/j)) x.at(i/j)^=x.at(i);
    }
  }

  cout<<c<<endl;
  REP(i,n) if(x.at(i)) cout<<i<<" ";
}