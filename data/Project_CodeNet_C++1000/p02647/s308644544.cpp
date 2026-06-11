#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,k,i,j;
  cin>>n>>k;
  vector<int> a(n+1),b(n+1);
  for(i=1;i<=n;i++) cin>>a.at(i);
  for(i=1;i<=min(k,100);i++){
    vector<int> b(n+1);
    for(j=1;j<=n;j++){
      b.at(max(1,j-a.at(j)))++;
      if(j+a.at(j)<n) b.at(j+a.at(j)+1)--;
    }
    for(j=2;j<=n;j++) b.at(j)+=b.at(j-1);
    a=b;
    bool f=true;
    for(j=1;j<=n;j++){
      if(a.at(j)<n){
        f=false;
        break;
      }
    }
    if(f==true) break;
  }
  for(i=1;i<=n;i++){
    cout<<a.at(i);
    if(i==n) cout<<endl;
    else cout<<' ';
  }
}