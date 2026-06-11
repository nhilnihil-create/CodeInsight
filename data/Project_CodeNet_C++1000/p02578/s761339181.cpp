#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,maximum;
  maximum=0;
  cin>>n;
  long long ans=0;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  maximum=a.at(0);
  for(int i=0;i<n;i++){
    if(maximum>a.at(i)){
      ans=ans+maximum-a.at(i);
    }
    maximum=max(maximum,a.at(i));
  }
  cout<<ans;
}