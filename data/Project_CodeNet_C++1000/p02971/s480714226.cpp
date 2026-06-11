#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n),s(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    s[i]=a[i];
  }
  sort(s.begin(),s.end());
  reverse(s.begin(),s.end());
  for(int i=0;i<n;i++){
    int ans=s[0];
    if(a[i]==ans){
      ans=s[1];
    }
    cout<<ans<<endl;
  }
  return 0;
}