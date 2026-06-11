#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int h,n;
vector<pair<int,int>>v;
int cache[1001][10001];
int dp(int pos,int hl)
{
    if(hl<=0)
        return 0;
    if(pos==n)
        return 1e18;
    int &ans=cache[pos][hl];
    if(ans!=-1)
        return ans;
    ans=dp(pos+1,hl);
    ans=min(ans,v[pos].second+dp(pos,hl-v[pos].first));
    return ans;
}
int32_t main() 
{
    IOS
    cin>>h>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    memset(cache,-1,sizeof(cache));
    print(dp(0,h));
}   
