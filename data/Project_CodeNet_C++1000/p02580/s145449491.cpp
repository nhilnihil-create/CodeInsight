#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define  fo(i,a,b) for(ll i=a;i<b;i++)
#define rfo(i,a,b) for(ll i=a;i>=b;i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#define err() cout<<"----------"<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define pb push_back
#define deb(x) cout<< #x << " = "<<x<<endl;
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589
const ll MOD=1e9+7;
ll mod(ll x)
{
   return (x%MOD+MOD)%MOD;
   // works for neg and pos values of x.
}
vector <ll> row[300005];
multiset <ll> best;
ll col[300005];
void upd(ll pos,ll del)
{
    best.erase(best.find(col[pos]));
    col[pos]+=del;
    best.insert(col[pos]);
}
void solve()
{
    ll n,m,k,x,y;
    cin>>n>>m>>k;
    fo(i,1,m+1)
    {
        best.insert(0);
    }
    fo(i,0,k)
    {
        cin>>x>>y;
        row[x].pb(y);   
        upd(y,1);
    }
    ll ans=0;
    fo(i,1,300005)
    {
        if(row[i].size()!=0)
        {
            for( ll ele : row[i])
            {
                upd(ele,-1);
            }
            ll sum=row[i].size();
            sum+=*best.rbegin();
            ans=max(ans,sum);
            for( ll ele : row[i])
            {
                upd(ele,1);
            }
        }
    }
    cout<<ans;


}
int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
//  clock_t time_req;
//  time_req = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }

// time_req = clock()-time_req;
//  cout<<"Time taken: "<<(float)time_req/CLOCKS_PER_SEC<<"s"<<endl;

    return 0;
}