#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n;
int arr[2005];
int cache[2006][2006];
vector<pair<int,int>>v;
int dp(int st,int en)
{
    int pos=st+n-1-en;
    if(pos==n)
        return 0;
    int &ans=cache[st][en];
    if(ans!=-1)
        return ans;
    ans=max(v[pos].first * abs(st-v[pos].second) + dp(st+1,en),
        v[pos].first * abs(en-v[pos].second) + dp(st,en-1));
    return ans;
}
int32_t main() 
{
    IOS;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        v.push_back({arr[i],i});
    }
    sort(v.rbegin(),v.rend());
    memset(cache,-1,sizeof(cache));
    cout<<dp(0,n-1);
}   
