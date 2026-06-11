#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,i,j,k,m=0;
  cin>>n;
  vector<int> a(n+1),b(n+1);
  for(i=1;i<=n;i++) cin>>a.at(i);
  for(i=n;i>0;i--){
    k=0;
    j=2;
    while(j*i<=n){
      k+=b.at(j*i);
      j++;
    }
    if((k+a.at(i))%2==1){
      m++;
      b.at(i)=1;
    }
  }
  cout<<m<<endl;
  j=0;
  for(i=1;i<=n;i++){
    if(b.at(i)==1){
      cout<<i;
      j++;
      if(j<m) cout<<' ';
      else{
        cout<<endl;
        break;
      }
    }
  }
}