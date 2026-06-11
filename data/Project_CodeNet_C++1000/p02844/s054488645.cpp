#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; 
using namespace std;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
typedef long long  ll;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;
#define pb push_back

#define F first
#define S second
#define SZ(a) int((a).size())
#define ALL(a) a.begin(),a.end()
#define fr(i,x,y) for(int i=x;i<y;i++)
#define frr(i,x,y) for(int i=x-1;i>=y;i--)
#define inf 1e18+1
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll power(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;}a=a*a;b>>=1;}return ans;}
ll powerm(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;ans%=mod;}a=a*a;a%=mod;b>>=1;}return ans%mod;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

void solve()
{
    ll n;
    cin>>n;
    string str;
    cin>>str;
    vector<VL> arr(10,VL());
    fr(i,0,SZ(str))
    {
        arr[str[i]-'0'].pb(i);
    }
    ll ans=0;
    fr(i,0,1000)
    {
        ll last=-2,fg=1;
        string s(3,'0');
        ll tp=i;
        ll id=2;
        while(tp!=0)
        {
            ll rem=tp%10;
            tp/=10;
            s[id]+=rem;
            id--;
        }
        //cout<<s<<endl;
        fr(j,0,3)
        {
            auto low=lower_bound(ALL(arr[s[j]-'0']),last+1);
            if(low==arr[s[j]-'0'].end()){
                fg=0;break;
            }
            else
                last=*low;
        }
        // if(i==0)
        // {
        //     fr(j,0,3)
        //     {
        //         auto low=lower_bound(ALL(arr[0]),last+1);
        //         if(low!=arr[0].end())
        //             last=*low;
        //         else
        //             fg=0;

        //     }
        // }
        // else if(i<10)
        // {
        //     fr(j,0,2)
        //     {
        //         auto low=lower_bound(ALL(arr[0]),last+1);
        //         if(low!=arr[0].end())
        //             last=*low;
        //         else
        //             fg=0;
        //     }
        //     auto low=lower_bound(ALL(arr[i]),last+1);
        //     if(low!=arr[0].end())
        //         last=*low;
        //     else
        //         fg=0;
        // }
        // else if(i<100)
        // {
        //     fr(j,0,1)
        //     {
        //         auto low=lower_bound(ALL(arr[0]),last+1);
        //         if(low!=arr[0].end())
        //             last=*low;
        //         else
        //             fg=0;
        //     }
        //     ll nm=0,tmp=i;
        //     while(tmp!=0)
        //     {
        //         nm=nm*10+tmp%10;
        //         tmp/=10;
        //     }
        //     while(nm!=0)
        //     {
        //         ll p=nm%10;
        //         nm/=10;
        //         auto low=lower_bound(ALL(arr[p]),last+1);
        //         if(low!=arr[0].end())
        //             last=*low;
        //         else
        //             fg=0;
        //     }
        // }
        // else
        // {
        //     ll nm=0,tmp=i;
        //     while(tmp!=0)
        //     {
        //         nm=nm*10+tmp%10;
        //         tmp/=10;
        //     }
        //     while(nm!=0)
        //     {
        //         ll p=nm%10;
        //         nm/=10;
        //         auto low=lower_bound(ALL(arr[p]),last+1);
        //         if(low!=arr[0].end())
        //             last=*low;
        //         else
        //             fg=0;
        //     }

        // }
        if(fg==1)
            ans++;
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    IOS;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
*/
// BITMASK:
// 1)When some constrall is of the order of 15-20, think of bitmask DP.
// 2)When some constrall is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algorithm