#include<bits/stdc++.h>
#define int long long
#define Inf 1000000000LL
using namespace std;
signed main(){
  int n,sum=0,a[1000000],z=0;
  string s[10000],b;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s[i]>>a[i];
  }
  cin>>b;
  for(int i=0;i<n;i++){
    if(b==s[i]){
      z++;
    }else if(z>0){
      sum+= a[i];
   }
  }
  cout<<sum<<"\n";
}