/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
const int MAXN = 13 ;
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
int c[MAXN] ;
int a[MAXN][MAXN] ;
int main()
{
    fio ;
    /* ======================Start of code ================ */
    int n,m,x;cin>>n>>m>>x ;
    f(i,0,n)
    {   
        cin>>c[i] ;
        f(j,0,m) cin>>a[i][j] ;
    }
    int ans = INT_MAX ;
    f(mask,0,(1<<n))
    {
        vector<int> ul(m,0) ;
        int cost = 0 ;
        f(j,0,n)
        {
            if((1<<j)&mask) // jth book is bought
            {
                cost+=c[j] ;
                f(k,0,m) ul[k]+=a[j][k] ;
            }
        }
        bool done = true ;
        f(k,0,m) if(ul[k]<x) 
        {
            done = false ;
            break ;
        }
        if(done)
            ans = min(ans,cost) ;
    }
    cout<<(ans==INT_MAX?-1:ans)<<"\n" ;
    /* ======================End of code ================== */
}