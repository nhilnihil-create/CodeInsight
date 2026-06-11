#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
const int N=2e6+5;
int mod=1e9+7;
ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}
int n,q;
int inter(int mx,pair<int ,int>p,pair<int ,int>f)
{
    pair<int,int>ans;
    ans.first=min(max(mx+1,p.first),p.second+1);
    ans.second=max(min(p.second,f.first-1),p.first-1);

    return max(0,((ans.second-ans.first)+1));
}
int xxx=0;
vector<int>build(vector<pair<int,int>>v)
{
    vector<vector<int>>add(n+2),rem(n+2);
    vector<int>t;
    t.resize(v.size(),0);
  set<int>st;
    for(int i=0; i<v.size(); i++)
    {
        add[v[i].first].push_back(i);
        rem[v[i].second+1].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        while(add[i].size())
        {
            st.insert(add[i].back());
            add[i].pop_back();
        }
        while(rem[i].size())
        {
            st.erase(rem[i].back());
            rem[i].pop_back();
        }
        if(st.size()==0)
            xxx++;
        else if(st.size()==1)
        {
            t[*(st.begin())]++;
        }
    }

    return t;
}

int solve2(vector<pair<int,int>>v)
{
    vector<int>t=build(v);
    int mn=1e9,mx=0;
    for(int i=0; i<v.size(); i++)
    {
        mn=min(mn,t[i]);
    }
    return mn;
}

int solve(vector<pair<int,int>>v)
{
    vector<int>t=build(v);
    int mn=1e9;
    for(int i=0; i<v.size(); i++)
    {
        mn=min(mn,t[i]);

    }

    int ans=1e9;
    for(int i=v.size()-1; t.size(); i--)
    {
        if(t.back()==mn)
        {
            pair<int,int>tmp=v[i];
            v.erase((v.begin()+i));
            ans=min(ans,solve2(v));
            //   cout<<"Try==> "<<tmp.first<<"  "<<tmp.second<<" t = "<<t.back()<<" ans = "<<ans<<endl;
            v.insert((v.begin()+i),tmp);


        }
        t.pop_back();


    }
    return ans+mn;
}

int main()
{
    FIO
ll n,p,ans=0;
cin>>n>>p;
mod=p;
string s;
cin>>s;
if(p==2||p==5)
{
    for(int i=0;i<n;i++)
    {
     if((s[i]-'0')%p==0)
        ans+=(i+1);

    }

}
else
{
    ll po=1;
    ll sum=0;
    map<ll,ll>mp;
    mp[0]=1;

    for(int i=n-1;i>=0;i--)
    {
        sum=add(mul(s[i]-'0',po),sum);
        po=mul(po,10);
        ans+=mp[sum]++;




    }

}
cout<<ans;

}

