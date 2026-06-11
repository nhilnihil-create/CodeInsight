#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> p(n),q(n);
  for(int i=0;i<n;i++)cin>>p[i];
  for(int i=0;i<n;i++)cin>>q[i];
  
  vector<long long> a(n),ans;
  for(int i=0;i<n;i++)a[i]=i+1;
  long long cnt=0;
  do{
    cnt++;
    bool ok1=true;
    for(int i=0;i<n;i++){
      if(a[i]!=p[i])ok1=false;
    }
    bool ok2=true;
    for(int i=0;i<n;i++){
      if(a[i]!=q[i])ok2=false;
    }
    if(ok1)ans.push_back(cnt);
    if(ok2)ans.push_back(cnt);
  }while(next_permutation(a.begin(),a.end()));
  cout<<abs(ans[1]-ans[0])<<endl;
  return 0;
}
  