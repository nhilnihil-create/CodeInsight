
// Problem : B - Substring
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
const long long int  modu=1e9+7;
#define endl '\n'
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define inp(x)  for(auto &t:x) cin>>t;
#define itr     vector<int>::iterator
#define debug(a) cout << #a << "=" << a << ' '<<endl;
#define out(x)  for(auto &t:x) cout<<t<<" "; cout<<endl;
#define ff first
#define ss second
#define pb push_back
#define initialize(a,v)  for(int i=0;i<a.size();++i) a[i]=v;
#define all(x) x.begin(),x.end()
#define mpt(mp) for(auto it=mp.begin();it!=mp.end();it++)
#define trav(x) for(int i=0;i<(int)x.size();++i)
#define mkp(a,b) make_pair(a,b)
#define sz(x)  (int)x.size()

int noofdig(int N)
{
	return floor(log10(N))+1;
}


ll f(ll a)
{

return 0;

}



void pre()
{

}

int f(string w,string t)
{
   int n=t.length();
   int cnt=0;
   for(int i=0;i<n;++i)
   {
   	if(w[i]!=t[i])
   	cnt+=1;
   }
	
	return cnt;
}



void solve()
{
	string s,t;
	cin>>s>>t;
	string window;
	int n=s.length();
	int m=t.length();
   int ans=0;
	
	for(int i=0;i<m;++i)
	window+=s[i];
	
	//debug(window);
	
	ans=f(window,t);
	
	
	for(int i=m;i<n;++i)
	{
		window.erase(window.begin());
		window+=s[i];
		//debug(window);
		
		int tmp=f(window,t);
		//debug(tmp);
		
		ans=min(ans,tmp);
	}
	
	cout<<ans<<endl;
	
	
	






}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
