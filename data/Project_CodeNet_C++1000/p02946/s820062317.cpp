#include<bits/stdc++.h>
using namespace std;
int main() {
  int k,x,i;
  cin>>k>>x;
  for(i=x-k+1;i<=x+k-1;i++){
    cout<<i;
    if(i==x+k-1) cout<<endl;
    else cout<<' ';
  }
}