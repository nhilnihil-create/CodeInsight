#include <bits/stdc++.h>
using namespace std;


int main(){
int n,sum=0;
  cin>>n;
  vector<int> v(n-1);
  for(int i=0;i<n-1;i++){
  cin>>v[i];
  }

  for(int i=n-2;i>0;i--){
  sum+=min(v[i],v[i-1]);
  }
  cout<<sum+v[0]+v[n-2];
  
  
  return 0;
}
