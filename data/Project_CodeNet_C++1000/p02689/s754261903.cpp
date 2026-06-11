#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<long long> h(n);
  for(int i=0;i<n;i++)cin>>h.at(i);
  vector<int> a(m),b(m);
  vector<bool> ok(n,true);
  for(int i=0;i<m;i++)cin>>a.at(i)>>b.at(i);
  for(int i=0;i<m;i++){
    a.at(i)--;
    b.at(i)--;
    if(h.at(a.at(i))>=h.at(b.at(i)))ok.at(b.at(i))=false;
    if(h.at(b.at(i))>=h.at(a.at(i)))ok.at(a.at(i))=false;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(ok.at(i))ans++;
  }
  cout<<ans<<endl;
  return 0;
}
