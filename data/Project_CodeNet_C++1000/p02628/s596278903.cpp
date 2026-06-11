#include<bits/stdc++.h>
using namespace std;
int main(){
 int a,b;
  cin>>a>>b;
  vector<int> v;
  v.resize(a);
  for(int i = 0 ; i < a ; i++) cin>>v[i];
  sort(v.begin(), v.end());
  int ans=0;
  for(int i = 0 ; i < b ; i++)ans+=v[i];
  cout<<ans<<endl;
}