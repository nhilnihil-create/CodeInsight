#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define PI acos(-1)
#define pb push_back
#define int long long
#define ld long double
#define sp fixed<<setprecision
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int M = (1e9)+7;
const int N = 1e6+5;

signed main()
{
    FAST
    int tc=1;
	//cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        int n,x;
      	cin>>n;
      	int f[n+1] = {},cnt_f[n+1] = {},pre[n+1] = {},suf[n+1] = {};
      	for(int i=0;i<n;i++)cin>>x,f[x]++;
	    for(int i=1;i<=n;i++)cnt_f[f[i]]++;
	    for(int i=1;i<=n;i++)pre[i] = (i*cnt_f[i]) + pre[i-1];
      	suf[n] = cnt_f[n];
      	for(int i=n-1;i>=0;i--)suf[i] = suf[i+1] + cnt_f[i];
      	int ans[n+1] = {};
      	for(int i=1;i<=n;i++)
        {
          	int max_k = suf[i];
	        max_k += pre[i-1]/i;
          	ans[max_k] = max(ans[max_k],i);
        }
      	for(int i=n-1;i>=1;i--)ans[i] = max(ans[i+1],ans[i]);
      	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
    }
    return 0;
}
