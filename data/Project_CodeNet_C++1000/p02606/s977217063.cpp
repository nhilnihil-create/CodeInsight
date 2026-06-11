#include<bits/stdc++.h>
using namespace std ;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define F  first
#define S  second

/*
bool compare (pair<ll,ll> x,pair<ll,ll> y)
    {   
        if(x.F==y.F)return x.S<y.S;
        return x.F<y.F;
    }
*/
/*
ll lcm(ll a,ll b)
    {
        return (a*b)/__gcd(a,b) ;
    }
*/
int main()
{
    /*  if you are getting wrong on test case 2 then think of another proper logic 
        if you are getting wrong on test case 4 then think of edge cases 
        like n=0,n=n-1&& k=0&& k=k-1;
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t>0)
    {
        t--;
        ll n,k,a,b,c,x,y,z;
        ll max=LONG_MIN;
        ll min=LONG_MAX;
        ll flag=0,sum=0;
        ll cnt=0,ans=0,gcd=1;
        cin>>a>>b>>c;
        ll i=0,j=0,l=0;
        for(ll i=a;i<=b;i++)
            {
            	if(i%c==0)cnt++;
            }
        cout<<cnt<<"\n";
    }
}