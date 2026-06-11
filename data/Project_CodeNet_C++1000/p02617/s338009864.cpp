//      https://www.youtube.com/watch?v=RBtlPT23PTM

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long unsigned llu;
typedef pair<long long, long long> pll;
const long long inf = 2000000000000000000LL;    // 2e18
#define pi                  acos(-1.0)
#define fast                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nl                  "\n"
#define ff                  first
#define ss                  second
#define pb                  push_back
#define pf                  push_front
#define all(x)              x.begin(),x.end()
#define debug(x)            cout<<"debug "<<x<<"\n"

int main()
{
    fast;
    ll t,i,j,k,l,m,n,o,p,q,temp,ans=0,flag=0,mod=1000000007,zero=0;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>j>>k;
        if(j>k) swap(j,k);
        ans-=(j*(n-k+1));
    }
    for(i=1;i<=n;i++){
        ans+=(i*(n-i+1));
    }
    cout<<ans;
}
