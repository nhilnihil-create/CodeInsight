#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int main() 
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
  ll n,m,p,l;cin>>n>>m>>p;
  if(m==0)
  {
  while(n--)cout<<p-1<<" ";
  }
  //cout<<min((p/n),(p/m));
  else {
  ll rest=n-m;
  while(m--)cout<<p<<" ";
    if(p==1)l=2;
    else l=p-1;
  while(rest--)cout<<l<<" ";}
 return 0;
}
