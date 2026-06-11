#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> p(n);
  for(int i=0;i<n;i++)cin>>p[i];
  
  int ans=1;
  int m=p[0];
  for(int i=1;i<n;i++){
    if(p[i]<=m){
      ans++;
      m=p[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}