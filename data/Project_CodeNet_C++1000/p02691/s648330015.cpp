#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <set>
#include <utility>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define IO ios::sync_with_stdio(false);
#define ll long long
#define pb push_back
using namespace std;
const double PI=acos(-1.0);
const int N=2e6+10;
const ll mod=1e9+7;
ll a[N];
map<ll,ll>mpl;
map<ll,ll>mpr;
void sovle()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mpl[i-a[i]]++;
        mpr[i+a[i]]++;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int cur1=mpr[i-a[i]];
        int cur2=mpl[i+a[i]];
        ans+=cur1+cur2;
    }
    ans/=2;
    cout<<ans<<endl;
}
int main()
{
//    int t;
//    cin>>t;
//    while(t--)
//    {
        sovle();
//    }
    return 0;
}
