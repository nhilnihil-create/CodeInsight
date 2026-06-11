#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
  int n;cin>>n;
  int k=0;
  n-=400;
  if(n<200)k=8;
  else if(n<400)k=7;
  else if(n<600)k=6;
  else if(n<800)k=5;
  else if(n<1000)k=4;
  else if(n<1200)k=3;
  else if(n<1400)k=2;
  else if(n<1600)k=1;
  cout<<k;
}