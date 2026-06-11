# include <bits/stdc++.h>
#define flash ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
#define ll long long int
#include <tr1/unordered_map>
#define ld long double
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f(i,a,b)  for(long long i=a;i<b;i++)
#define all(c) (c).begin(),(c).end()
#include <map>

using namespace std;

int main()
{



     flash;
     ///////////////////////////////////////////////////////////////////////////////////////

ll n;
cin>>n;
ll dir[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
ll maxi[4]={INT_MIN,INT_MIN,INT_MIN,INT_MIN};
ll mini[4]={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
for(ll i=0;i<n;i++)
{
    ll x,y;
    cin>>x>>y;
    for(ll j=0;j<4;j++)
    {
    maxi[j]=max(maxi[j],x*dir[j][0]+y*dir[j][1]);
    mini[j]=min(mini[j],x*dir[j][0]+y*dir[j][1]);
}

}
ll ans=INT_MIN;
for(ll i=0;i<4;i++)
{
    ans = max(ans,maxi[i]-mini[i]);

}
cout<<ans<<endl;









    ///////////////////////////////////////////////////////////////////////////////////////

     return 0;

}
