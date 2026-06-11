#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int k,n; cin>>k>>n;
  vector<int> a(n);
  for(int &i:a)
    cin>>i;
  vector<int> dis(n);
  
  dis[0]=a[0]+k-a[n-1];
  for(int i=1;i<n;i++)
    dis[i]=a[i]-a[i-1];
  
  sort(dis.rbegin(),dis.rend());
  
  cout<<k-dis[0]<<endl;
}