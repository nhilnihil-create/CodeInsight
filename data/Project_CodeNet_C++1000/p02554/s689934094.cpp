#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);

#define endl "\n";


#define mod 1000000007
#define loop(i,s,n)  for(ll i=s;i<n;i++)
#define test  ll t; cin>>t; while(t--)
#define p push_back
typedef long long ll;
ll  mexp(ll k,ll n,ll m)
{if(n==0)
{return 1;}
else if(n%2==0)
{return mexp((k*k)%m,n/2,m);}
else
{return (k*mexp((k*k)%m,(n-1)/2,m))%m;}}




int main()
{

ll n,i,j,k,count=0,sum=1;
cin>>n;
count=((mexp(10,n,mod)%mod)-((2*mexp(9,n,mod))%mod)+(mexp(8,n,mod)%mod));
count=(count+mod)%mod;

cout<<count;

    return 0;
}


