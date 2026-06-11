/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
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

int main()
{
    fio ;
    /* ======================Start of code ================ */
    ld a,b,h,m;cin>>a>>b>>h>>m ;
    ld thetaH = h*30+(m/2) ;
    ld thetaM = 6*m ;
    ld thetaB = abs(thetaH-thetaM) ;
    ld rad = (M_PI*thetaB)/180 ;

    ld ans = sqrt(a*a+b*b-2*a*b*cos(rad)) ;
    cout<<setprecision(18)<<ans<<"\n" ;
    /* ======================End of code ================== */
}