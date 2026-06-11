#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin>>v.at(i);
  }
  sort(v.begin(),v.end());
  double ans=v.at(0);
  for(int i=1; i<n; i++){
    ans=(ans+v.at(i))/2;
  }
  cout<<ans<<endl;
}
