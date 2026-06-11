#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
int n,q,a[N],b[N];
int get(int x,int y,int z){
  for(int i=1;i<=n;i++)b[i]=a[i]%z;
  int l=x/n;
  int r=x%n;
  y%=z;
  int ans1=0,ze=0;
  for(int i=1;i<=n;i++){
    if(!b[i])ze++;
  }
  ans1+=ze*l;
  ze=0;
  for(int i=1;i<=r;i++){
    if(!b[i])ze++;
  }
  ans1+=ze;
  LL tot=0;
  for(int i=1;i<=n;i++){
    tot+=b[i];
  }
  tot=1ll*tot*l;
  for(int i=1;i<=r;i++)tot+=b[i];

  //cout<<tot+y<<endl;
  return x-ans1-(tot+y)/z;
}
int main() {
  ios::sync_with_stdio(false);
   cin>>n>>q;
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=q;i++){
     int a,b,c;
     cin>>a>>b>>c;
     --a;
     cout<<get(a,b,c)<<'\n';
   }
  return 0;
}