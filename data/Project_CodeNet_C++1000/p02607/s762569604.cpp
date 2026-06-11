#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,ans=0;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if((i+1)%2!=0&&arr[i]%2!=0)
      ans++;
  }
  cout<<ans<<"\n";
  return 0;
}