#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof (a))
#define gcd(a,b) __gcd(a,b)
#define all(a) a.begin(),a.end()
#define in(a) insert(a)
#define sz() size()
#define endl '\n'
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=100010;
const ll inf=1e18;
const ll mod=998244353;
const double pi=3.14159265358979;
const double ep=0.0;
ll a[maxn];
int main(){
    int n;
    cin>>n;
    ll sum=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        sum^=a[i];
    }
    ll ans=0,b=0;
    vector<int> vis(n);
    for(int j= 61;j>=0;j--)
    {
        if(sum&(1ll<<j))
            for (int i=0;i<n;i++)
                if(a[i]&(1ll<<j))
                    a[i]^=1ll<<j;
        for (int i=0;i<n;i++)
        {
            if(vis[i])
                continue;
            if(a[i]&(1ll<<j))
            {
                vis[i]=1;
                for (int k=0;k<n;k++)
                {
                    if(i==k)
                        continue;
                    if(a[k]&(1ll<<j))
                    a[k]^=a[i];
                }
                break;
            }
        }
    }
    sort(a,a+n);
    reverse(a,a+n);
    n=min(65,n);
    int t=40000;
    while (t--)
    {
        for (int i=0;i<n;i++)
            vis[i]=0;
        b=0;
        for(int j=61;j>=0;j--)
        {
            if(b&(1ll<<j))
                continue;
            for (int i=0;i<n;i++)
                if(!vis[i]&&a[i]&(1ll<<j))
                {
                    b^=a[i];
                    vis[i]=1;
                    break;
                }
        }
        ans=max(ans,b+(b^sum));
        random_shuffle(a, a+n);
    }
    cout<<ans<<endl;
    return 0;
}
