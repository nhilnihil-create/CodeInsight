#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;cin>>n;
  vector<int> a(n+1,0),x(n+1,0),ans(n+1,0);
  for(int i=1;i<=n;i++) cin>>a.at(i);

  for(int i=n;i>=1;i--){
    ans.at(i)=x.at(i)^a.at(i);
    for(int j=1;j*j<=i;j++){
      if(!(i%j)){
        x.at(j)=x.at(j)^ans.at(i);
        if((j!=1)&&(j!=i/j)) x.at(i/j)=x.at(i/j)^ans.at(i);
      }
    }
  }

  int count=0;
  for(int i=1;i<=n;i++) if(ans.at(i)) count++;
  cout<<count<<endl;
  for(int i=1;i<=n;i++) if(ans.at(i)) cout<<i<<" ";
}