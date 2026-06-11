#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
const int N=1e7+5, mxN=1e7;
int mod=1000000007 ;
ll mul(ll x, ll y)
{
    x%=mod;
    y%=mod;
    return (x*y)%mod;
}
ll add(ll x, ll y)
{
    x%=mod;
    y%=mod;
    return (x+y+mod)%mod;
}
ll fast_pow(ll b, ll p)
{
    if(!p)return 1;
    ll ans=fast_pow(b,p/2);
    ans=mul(ans,ans);
    if((p&1))ans=mul(ans,b);
    return ans;
}
string s;
bool check(int d)
{
    if(d>s.size()/2)
    return 0;

    string temp;
    for(int i=0;i<d;i++)
        temp.push_back(s[i]);
    map<string,vector<int>>mp;
   mp[temp].push_back(d-1);

    for(int i=d;i<s.size();i++)
    {
        temp.push_back(s[i]);
        temp.erase(0,1);

        mp[temp].push_back(i);
        if(mp[temp].size()>1)
        {
            if(mp[temp].back()-mp[temp].front()>=d)
                return 1;
        }
    }
    return 0;


}
int main()
{


int n;
cin>>n>>s;
int low=1,high=n/2;
int ans=0;
while(low<=high)
{
    int mid=(low+high)/2;
    if(check(mid))
    {
        ans=mid;
        low=mid+1;
    }
    else high=mid-1;


}
cout<<ans;
    return 0;
}
