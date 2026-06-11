//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,m;
int cost[1005];
int bitval[1005];
int cache[1005][5000];
int dp(int pos,int bit)
{
    if(pos==m)
    {
        if(bit+1==(1<<n))
            return 0;
        return 1e18;
    }
    int &ans=cache[pos][bit];
    if(ans!=-1)
        return ans;
    ans=min(cost[pos]+dp(pos+1,bit|bitval[pos]),dp(pos+1,bit));
    return ans;
}
int32_t main() 
{
    IOS;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        cost[i]=a;
        int val=0;
        for(int j=0;j<b;j++)
        {
            int c;
            cin>>c;
            c--;
            val|=(1ll<<c);
        }
        bitval[i]=val;
    }
    memset(cache,-1,sizeof(cache));
    print(dp(0,0)>1e17?-1:dp(0,0));
}