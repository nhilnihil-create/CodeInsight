#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
#define int long long
const ll MOD=1e9+7LL;
const int N=200100;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll rs=0LL,r=0,x,y,init=0;
    for (int i = 0; i < n; ++i)
    {
    	cin>>x>>y;
    	while(y > 1)
    	{
    		if(y%2==1)
    		{
    			r+=x;
    			if(init)
    				rs++;
    			init=1;
    			while(r>=10)
    			{
    				rs++;
    				r=r/10 +r%10;
    			}
    		}
			rs+=y/2;
			x+=x;
			if(x>=10)
			{
				rs+=y/2;
				x=x/10 +x%10;
			}
			y/=2;
    	}
    	// cout<<x<<" "<<y<<"\n";
    	r+=x;
    	if(init)
			rs++;
		init=1;
    	while(r>=10)
		{
			rs++;
			r=r/10 +r%10;
		}
    }
    cout<<rs<<"\n";
    return 0;   
}