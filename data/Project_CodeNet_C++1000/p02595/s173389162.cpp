#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  
  int n,k;
  cin>>n>>k;
  int cnt = 0;
  for(int i=1;i<=n;i++){
    ll a,b;
    cin>>a>>b;
    if(sqrt(a*a+b*b)<=k) cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}