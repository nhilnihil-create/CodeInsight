#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<long long> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  long long ans=a[0];
  int cnt=1;
  bool ng=false;
  for(int i=1;i<n;i++){
    for(int j=0;j<2;j++){
      if(cnt==n-1){
        ng=true;
        break;
      }
      ans+=a[i];
      cnt++;
    }
    if(ng)break;
  }
  cout<<ans<<endl;
  return 0;
}
