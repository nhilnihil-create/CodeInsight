#include<bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define mp  make_pair
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define inf 1e18 
 
using namespace std;
 
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
    IOS;
    int n,x,y,i,j;
    cin>>n>>x>>y;
    vi v(n);
    for(i=1;i<n;i++)
    {
        int ans=0;
        for(j=i+1;j<=n;j++)
        {
            int dis=j-i;
            dis=min(dis,abs(x-i)+abs(y-j)+1LL);
            v[dis]++;
        }
    }
    for(i=1;i<n;i++) cout<<v[i]<<endl;
}