#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  string s; cin>>s;
  vector<int> r,g,b;
  for(int i=0; i<n; ++i){
    if(s[i]=='R') r.push_back(i);
    else if(s[i]=='G') g.push_back(i);
    else b.push_back(i);
  }
  int x,y,z;
  long long res=0;
  for(x=0; x<r.size(); ++x)
    for(y=0; y<g.size(); ++y){
      int p=max(r[x],g[y]),q=min(r[x],g[y]),d=p-q,cnt=b.size();
      if(binary_search(b.begin(),b.end(),p+d)==true) --cnt;
      if(binary_search(b.begin(),b.end(),q-d)==true) --cnt;
      if(((p+q)&1)==0) if(binary_search(b.begin(),b.end(),(p+q)/2)==true) --cnt;
      res+=cnt;
    }
  cout<<res;
  return 0;
}