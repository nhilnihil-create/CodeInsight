#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ans;

signed main(){
  int k,q;cin>>k>>q;
  vector<int> d(k);
  for(int i=0;i<k;i++)cin>>d[i];
  while(q--){
    int n,x,m;cin>>n>>x>>m;n--;
    int a=0;
    for(int i=0;i<k;i++)a+=(d[i]%m?d[i]%m:m);
    a*=n/k;
    a+=x%m;
    for(int i=0;i<n%k;i++)a+=(d[i]%m?d[i]%m:m);
    ans.push_back(n-a/m);
  }
  for(int p:ans)cout<<p<<endl;
}
