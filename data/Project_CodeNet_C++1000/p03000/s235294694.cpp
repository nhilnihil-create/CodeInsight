#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,ans=0,count=1;
  cin>>n>>m;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    ans = ans + a[i];
    if(ans<=m){
      count++;
    }
  }
  cout<<count<<endl;
} 