#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n%2==1){
    cout<<"0\n";
    return 0;
  }
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
sort(a.begin(),a.end());
  cout<<a[n/2]-a[n/2-1]<<endl;
  return 0;
}