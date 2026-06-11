#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll r,s,p;
    cin>>r>>s>>p;
    string t;
    cin>>t;
    t="#"+t;
    string sr="";
    rep(i,0,n+1)
    sr+="#";
    ll ans=0;
    rep(i,1,k+1)
    {
        if(t[i]=='r')
        {
            sr[i]='p';
            ans+=p;
        }
        if(t[i]=='s')
        {
            sr[i]='r';
            ans+=r;
        }
        if(t[i]=='p')
        {
            sr[i]='s';
            ans+=s;
        }
    }
    rep(i,k+1,n+1)
    {
        if(t[i]==t[i-k])
        {
            if(sr[i-k]=='#')
            {
                if(t[i]=='r')
        {
            sr[i]='p';
            ans+=p;
        }
        if(t[i]=='s')
        {
            sr[i]='r';
            ans+=r;
        }
        if(t[i]=='p')
        {
            sr[i]='s';
            ans+=s;
        }

            }
            else
            {
                continue;
            }
        }
        else
        {
            if(t[i]=='r')
        {
            sr[i]='p';
            ans+=p;
        }
        if(t[i]=='s')
        {
            sr[i]='r';
            ans+=r;
        }
        if(t[i]=='p')
        {
            sr[i]='s';
            ans+=s;
        }
        }
    }
    cout<<ans<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}