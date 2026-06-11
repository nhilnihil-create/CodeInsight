#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> d(n);
  for(int i=0;i<k;i++){
    int s;
    cin>>s;
    for(int j=0;j<s;j++){
      int a;
      cin>>a;
      d[a-1]=1;
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(d[i]==0){
      ans++;
    }
  }
  cout<<ans<<endl;
}