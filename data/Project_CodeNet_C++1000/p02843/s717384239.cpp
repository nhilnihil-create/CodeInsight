#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
  int n,m,k; cin>>n;
  m=n/100; k=n%100;
  if(m*5<k)cout<<0<<endl;
  else cout<<1<<endl;
}