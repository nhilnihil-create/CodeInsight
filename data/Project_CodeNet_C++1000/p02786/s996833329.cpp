#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long h;
  cin>>h;
  long long ans=0;
  long long factor=1;
  while(h>0){
    ans+=factor;
    h=h/2;
    factor=factor*2;
  }
  cout<<ans<<"\n";
  return 0;
}

