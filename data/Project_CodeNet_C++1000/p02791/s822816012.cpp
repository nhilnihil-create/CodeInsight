#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>> n;
  vector<int> p(n);
  for(int i=0; i<n; i++) cin>> p[i];
  
  int lowest=p[0],ans=0;
  for(int i=0; i<n; i++){
    if(lowest>=p[i]){ lowest=p[i]; ans++;}
  }
  cout<<ans<<endl;
}