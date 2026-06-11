#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,ans=0,j;
  int a[100002],b[100001];
  cin >> n;
  for(int i=0;i<=n;i++)cin >> a[i];
  for(int j=0;j<n;j++)cin >> b[j];
  for(int i=0;i<n;i++){
    j=min(a[i],b[i]);
    ans+=j;
    a[i]-=j;
    b[i]-=j;
    j=min(a[i+1],b[i]);
    ans+=j;
    a[i+1]-=j;
    b[i]-=j;
  }
  cout << ans << endl;
}
