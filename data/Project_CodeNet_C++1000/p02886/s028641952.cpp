#include<iostream>
#include<vector>

using namespace std;
main(){
  int n,s=0;
  cin>>n;
  vector<int> v(n+1);
  for(int i=1;i<=n;i++)cin>>v[i];
  for(int i=1;i<=n;i++){
    for(int  j=i+1;j<=n;j++){
      s+=v[j]*v[i]; 
    }
  }
  cout<<s;
  return 0;
}