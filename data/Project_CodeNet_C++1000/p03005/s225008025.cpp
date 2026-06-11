#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  if(k==1 || n-k<0) cout<<0<<endl;
  else cout<<n-k<<endl;
}