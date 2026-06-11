#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vpii vector<pair<int,int> >
#define X first
#define Y second
#define fr(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
#define fi ios_base::sync_with_stdio(false);cin.tie(NULL);

vector< vector<ll> >  v;
vector<ll> dum;
ll n,m,q,ans=0,qq;
void rec(ll i, ll a)
{
    if(i==n)
    {
        ll sum=0;
        for(int k=0;k<qq;k++)
        {
            if(dum[v[k][1]-1] - dum[v[k][0]-1] == v[k][2])
            sum+=v[k][3];
        }
        ans=max(ans,sum);
        return;
    }
    fr(j,a,m+1)
    {
        dum.pb(j);
        rec(i+1,j);
        dum.pop_back();
    }
}


int main()
{
    
    cin>>n>>m>>q;
  // int i=0;
    qq=q;
    vector<ll> vv(4,0);
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vv[0]=a;
        vv[1]=b;
        vv[2]=c;
        vv[3]=d;
       
        v.pb(vv);
   // i++;
    }
   
    
    rec(0,1);
    cout<<ans;
}