#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int main() 
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
  ll n,m,p;cin>>n>>m>>p;
  ll q=(p/n),w=(p/m);
  if((p%n)!=0)q++;
  if((p%m)!=0)w++;
  cout<<min(q,w);
 return 0;
}
