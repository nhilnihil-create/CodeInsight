#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n-1);
  vector<int> ans(n);
  for(int i=0;i<n-1;i++){
    cin>>a[i];
    a[i]--;
    ans[a[i]]++;
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}