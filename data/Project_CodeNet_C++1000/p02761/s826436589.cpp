#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,a,b;
  cin >> n >> m;
  bool t=true;
  int ans[n],num[n];
  for(int i=0;i<n;i++)ans[i]=0;
  if(m==0){
    if(n>=2)cout << 1;
    else cout << 0;
    for(int i=0;i<n-1;i++)cout << 0;
    cout << endl;
    t=false;
  }
  for(int i=0;i<m;i++){
    cin >> a >> b;
    if(num[a-1]==1 && ans[a-1]!=b){
      cout << -1 << endl;
      t=false;
    }
    ans[a-1]=b;
    num[a-1]=1;
    if(a==1 && b==0 && n>=2){
      t=false;
      cout << -1  << endl;
    }
  }
  if(t){
  for(int i=0;i<n;i++){
    if(num[i]==0 && i==0 && n>=2)ans[i]=1;
    else continue;
  }
  for(int i=0;i<n;i++)cout << ans[i];
  cout << endl;
  }
}