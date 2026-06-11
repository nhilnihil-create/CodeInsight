#include<bits/stdc++.h>
using namespace std;
int main() {
  int64_t n,a,b,i,s=0;
  map<int64_t,int64_t> m;
  string ans="Yes";
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a>>b;
    if(m.count(b)) m.at(b)+=a;
    else m[b]=a;
  }
  for(auto z:m){
    s+=z.second;
    if(s>z.first){
      ans="No";
      break;
    }
  }
  cout<<ans<<endl;
}