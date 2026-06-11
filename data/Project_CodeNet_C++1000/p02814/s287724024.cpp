#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,m;
  cin>>n>>m;
  vector<long long> a(n);
  long long memo=0;
  for(int i=0;i<n;i++){
    long long x,cnt=0;
    cin>>x;
    a[i]=x/2;
    while(x%2==0){
      x/=2;
      cnt++;
    }
    if(i==0) memo=cnt;
    if(i!=0&&cnt!=memo) {cout<<0<<endl; return 0;}
  }
  sort(a.begin(),a.end());
  long long mem;
  if(n==1) mem=a[0];
  else mem=a[0]/__gcd(a[0],a[1])*a[1];
  for(int i=2;i<n;i++){
    if(mem>m) {cout<<0<<endl; return 0;}
    if(mem%a[i]!=0) mem=mem/__gcd(mem,a[i])*a[i];
  }
  long long ans=0,me=mem;
   while(me<=m){
    ans++;
    me+=2*mem;
  }
  cout<<ans<<endl;
}
  