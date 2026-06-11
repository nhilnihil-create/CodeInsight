#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define lli long long int
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define mii map<lli,lli>
#define msi map<string,lli>
#define pii pair<lli,lli> 
#define vi vector<lli> 
#define vvi vector< vector<lli> >
#define sz(x) (lli)x.size()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX1 998244353
#define MAX2 1000000007
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define input(data,n,command) for(lli i=0;i<n;i++){lli tmp;cin>>tmp;data.pb(tmp);command}
#define sort_asc(a) sort(a.begin(),a.end());
//#define sort_desc(a) sort(a.begin(),a.end(),greater<lli>());
#define display(a) for(lli i = 0 ;i<a.size();i++){cout<<a[i]<<" ";} cout<<endl;
#define rep(i,a,b) for(lli i = a;i < b;i++)
#define endl "\n"

//Written By MUDIT BHARDWAJ...
/*--------------------------------------------------------------------*/
//vector<pair<lli,lli>>adj[300010];
lli n,k;
std::vector<lli> v;

lli calc(lli num)
{
	lli count = 0;
	rep(i,0,n)
	{
		lli x = v[i];
		if(x > num)
		{
			lli times = x/num;
			if(x%num)
			{
				count += times;
			}
			else
			{
				count += times-1;
			}
		}
	}
	if(count > k)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

lli solve()
{
    //start from here
    cin>>n>>k;
    rep(i,0,n)
    {
    	lli a;
    	cin>>a;
    	v.pb(a);
    }
    sort_asc(v);
    lli low = 1;
    lli high = 1000000000;
    lli mid;
    lli ans = MAX2;
    while(low + 1 < high)
    {
    	mid = (low + high)/2;
    	lli poss = calc(mid);
    	if(poss == 0)
    	{
    		low = mid + 1;
    	}
    	else
    	{
    		high = mid;
    		ans = min(ans,mid);
    	}
    }
    if(calc(low) == 1)
    {
    	ans = min(ans,low);
    }
    if(calc(high) == 1)
    {
    	ans = min(ans,high);
    }
    cout<<ans;
    return 0;
}

int main()
{
    ios
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli T=1;
    //cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
/*-----------------------------------------------------------------------*/