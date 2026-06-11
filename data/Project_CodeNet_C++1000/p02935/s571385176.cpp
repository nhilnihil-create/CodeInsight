#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<double> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  if(n==2){
    cout<<(v[0]+v[1])/2.0<<endl;
    return 0;
  }
  sort(v.begin(),v.end());
  double ans=(v[0]+v[1])/2.0;
  for(int i=0;i<n-2;i++){
    ans=(ans+v[i+2])/2.0;
  }
  cout<<ans<<endl;
}