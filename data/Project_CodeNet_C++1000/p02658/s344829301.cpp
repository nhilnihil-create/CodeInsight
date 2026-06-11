#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,flag=0; cin>>n; long long a[n];
  for(int i=0;i<n;i++){ cin>>a[i]; if(!a[i]) flag=1;}
  if(flag) { cout<<0<<endl; return 0;}
  long long c=1e18;
  long long prod=1;
  for(int i=0;i<n;i++){
    long long rem=c/prod;
    if(rem<a[i]) { prod=-1; break; }
    else prod*=a[i]; 
  }
  cout<<prod<<endl;
}