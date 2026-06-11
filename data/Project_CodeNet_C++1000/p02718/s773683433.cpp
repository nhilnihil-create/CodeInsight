#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int all=0,cnt=0;
  rep(i,n)all+=a[i];
  rep(i,n){
    if(all<=a[i]*4*m)cnt++;
  }
  if(cnt>=m)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}