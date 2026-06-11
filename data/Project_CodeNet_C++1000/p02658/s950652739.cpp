#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  unsigned long long ans=1;
  vector<long long> a(n);
  for(int i=0;i<n;i++)cin>>a.at(i);
  sort(a.begin(),a.end());
  if(a[0]==0){
    cout<<0<<endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    if(ans>(long long)1e18/a[i]){
      cout<<-1<<endl;
      return 0;
    }
    ans*=a[i];
  }
  cout<<ans<<endl;
  return 0;
}
