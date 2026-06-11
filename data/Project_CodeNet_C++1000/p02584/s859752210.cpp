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
	ll x,k,d; cin>>x>>k>>d;
	x = abs(x);

	ll mn = min(k,x/d);
	k -=mn;
	x = x-mn*d;

	if(k%2) {cout<<d-x;}
	else cout<<x;
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
