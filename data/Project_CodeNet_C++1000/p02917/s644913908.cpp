#include<bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef long double ld;
typedef vector<li> vi;
typedef pair<li,li> pi;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define B begin()
#define E end()
#define f(i,l,r) for(li i=l;i<=r;++i)
#define fr(i,l,r) for(li i=l;i>=r;--i)
#define u_map unordered_map
#define endl "\n"
#define debug(x) cout<<#x<<" = "<<x<<endl;

li fastpow(li base,li exp,li M) 
{
    li res=1;
    while(exp>0) {
        if(exp&1)
            res=(res*base)%M;

        base=(base*base)%M;
        exp>>=1;
    }
    return res;
}

void solve()
{
    li n;

    cin>>n;

    li sum=0;

    li b[n-1];

    f(i,0,n-2)
    {
        cin>>b[i];
    }

    sum+=2*b[n-2];

    fr(i,n-3,0)
    {
        if(b[i]<=b[i+1])
        {
            sum-=b[i+1];
            sum+=2*b[i];
        }
        else
        {
            sum+=b[i];
        }
    }

    cout<<sum;
}

int main()
{    
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    li t=1;

    // cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}