#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  long long ans=0;
  int t=n-1;
  sort(a.rbegin(),a.rend());
  for(int i=0;i<n;i++){
    int lim=2;
    if(i==0) lim=1;
    for(int j=0;j<lim;j++){
      if(t>0){
        ans+=a[i];
        t--;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
