#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<long long>lve;
typedef vector<pair<ll,ll> > lvp;

#define sp         ' '
#define endl       '\n'
#define F          first
#define S          second
#define pp         pop_back`
#define pb         push_back
#define mp         make_pair 
#define GCD(x,y)   __gcd(x,y)
#define PI         2*acos(0.0)
#define lb         lower_bound
#define bs         binary_search
#define all(x)     x.begin(),x.end()
#define LCM(x,y)   ((x*y)/__gcd(x,y))
#define btpc       __builtin_popcountll
#define spc(x)     cout<<fixed<<setprecision(x)

const   long long  cs=2e5+5;
const   long long  inf=1e18;
const   long long  mod=1e9+7;
void solve()
{
    int64_t t,n,m,a,b,c,d,e,i,j,k,x,y,cnt=0,cnt1=0;
    bool flag = false;   
    
    cin>>a>>b;
    n=2019;
    if(a%n==0 || b%n==0) 
    {
        cout<< 0 <<endl;
        return ;
    }
    if(abs(a-b)>=n)
    {
        cout<< 0 <<endl;
        return ;
    }
    cnt=inf;
    for(i=a;i<b;i++){
        for(j=i+1;j<=b;j++){
            n = i%2019;
            m = j%2019;
            cnt=min(cnt,(n*m)%2019);
        }
    }
    cout<<cnt<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    // freopen ("input.txt","r",stdin);
    // freopen ("output.txt","w",stdout);

    // int32_t tc;
    // cin>>tc;
    // while(tc--)
    solve();

    return 0;
}
