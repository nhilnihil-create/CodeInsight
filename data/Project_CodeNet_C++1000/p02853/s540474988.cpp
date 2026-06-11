#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
#define int long long
const ll MOD=1e9+7LL;
const int N=100100;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y,tot=0;
    cin>>x>>y;
    if(x==1 && y==1)
    	tot=400000;
    if(x<4)
    {
	    x=4-x;
	    tot+=(x)*100000;
    }

    if(y<4)
    {
	    y=4-y;
	    tot+=(y)*100000;
    }
    cout<<tot<<"\n";
    return 0;   
}