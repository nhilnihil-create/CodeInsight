#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> ans(10000000,0);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    for(int j=a[i];j<=a[n-1];j+=a[i]){
      ans[j]++;
    }
  }
  long long cnt=0;
  for(int i=0;i<n;i++){
    if(ans[a[i]]==1)cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
      