/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
// const int MAXN = 2e5+5 ;
#define pb push_back 
#define X first 
#define Y second 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define pli pair<ll,int> 
#define pil pair<int,ll> 
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setprecision(10) ;
#define is(x) cout<<#x<<" : "<<x<<endl ;
// #define DEBUG
ll po[205] ;
int main()
{
    fio ;
    /* ======================Start of code ================ */
    ll x;cin>>x ;
    f(i,0,204)
    {
        po[i] = 1LL*i*i*i*i*i ;
    }
    f(i,0,204)
    {
        f(j,0,i)
        {
            if(po[i]-po[j]==x)
            {
                return cout<<i<<" "<<j<<"\n",0 ;
            }
            if(po[i]+po[j]==x) return cout<<i<<" "<<-j<<"\n",0 ;
        }
    }
    int z=0 ;
    /* ======================End of code ================== */
}