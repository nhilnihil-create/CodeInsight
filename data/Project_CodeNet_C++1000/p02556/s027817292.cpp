
#include<bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#define pi 3.141592653589
#define MOD 1000000007
#define to() int t; cin>>t; while(t--)
#define pb push_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define si(s) s.size()
#define fori(it,v) for(it=v.begin();it!=v.end(); it++) 
#define for1(low,high,k) for(int i=low;i<high;i+=k)
#define for11(low,high,k) for(int j=low;j<high;j+=k)
#define for2(low,high,k) for(int i=low;i<=high;i+=k)
#define rev(high,low,k)  for(int i=high;i>=low ;i-=k)
#define all(x) x.begin(), x.end()
#define fil(x,i) memset(x,i,sizeof(x));
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout) 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

//bool cmp(pair<ll,ll>a,pair<ll,ll>b){
//	return abs(a.ff+a.ss)<abs(b.ff+b.ss);
//}

int main()
{
    boost;
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
	boost;
	int n; cin>>n;
	vector<pair<ll,ll> >v(n);
	ll maxi1=-1e9,mini1=1e15;
	ll maxi2=-1e9,mini2=1e15;
	for1(0,n,1){ cin>>v[i].ff>>v[i].ss; 
		maxi1=max(maxi1,v[i].ff+v[i].ss);
		mini1=min(mini1,v[i].ff+v[i].ss);
		maxi2=max(maxi2,v[i].ff-v[i].ss);
		mini2=min(mini2,v[i].ff-v[i].ss);
	}
	ll ans=max(maxi1-mini1,maxi2-mini2);
	//sort(all(v),cmp);
	//ll ans=abs(v[n-1].ff+v[n-1].ss)-abs(v[0].ff+v[0].ss);
	cout<<ans<<endl;
return 0;
}
