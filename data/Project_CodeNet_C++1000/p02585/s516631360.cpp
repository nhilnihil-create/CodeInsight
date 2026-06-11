#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD=1e9+7;

ll n,k,vis[5005];
ll p[5005],c[5005],sum[5005],ans=-1e18;

int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=1; i<=n; i++)
	{
        ll s=c[i];
        vector<ll> t; 
		t.push_back(s);
        for(int j=p[i]; j!=i; j=p[j]) s+=c[j],t.push_back(s);
        int len=t.size();
        for(int j=0;j<len;j++)
		{
            ll rest=k-j-1;
            if(rest<0) break;
            ans=max(ans,t[j]+(rest/len)*max(s,0LL));
        }
    }
    cout << ans;
}