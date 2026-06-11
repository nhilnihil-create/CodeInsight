#include<bits/stdc++.h>
using namespace std;
#define       M                        1000000007
#define       ll                       long long
#define	      FIO		                   ios_base::sync_with_stdio(false);cin.tie(NULL)
#define        ifor(st,lim)             for(int i=st;i<lim;i++)
#define       jfor(stt,llim)           for(int j=stt;j<llim;j++)
#define       eifor(st,lim)            for(int i=st;i<=lim;i++)
#define       ejfor(stt,llim)          for(int j=stt;j<=llim;j++)
#define       blank		                 cout<<'\n';

void solve()
{
    int n,x,t; cin>>n>>x>>t;
    int p = n/x;
    if(n%x == 0) cout<<t*p;
    else cout<<(p+1)*t; 
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
int t=1; 
  while(t--){
    solve();
   } 
}
