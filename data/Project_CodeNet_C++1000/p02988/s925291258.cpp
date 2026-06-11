#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,count=0,p[25];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>p[i];
    //cout<<p[i]<<endl;
  }
  for(int i=1;i<=n-2;i++){
    if(p[i-1]<p[i]&&p[i]<p[i+1]) count++;
    if(p[i-1]>p[i]&&p[i]>p[i+1]) count++;
  }
  cout<<count<<endl;
}
    