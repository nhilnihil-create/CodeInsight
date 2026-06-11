#include <bits/stdc++.h>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;

#define int ll
void solve()
{
  string s;
	cin>>s;
	vector<int>pos;
	int ans=0;
	if(s[0]=='<')s='>'+s,--ans;
	if(s.back()=='>')s+='<',--ans;
	int n=s.size();
	rep(i,n-1){
		if(s[i]=='>'&&s[i+1]=='<')pos.pb(i);
	}
	int pre=0;
	//cout<<ans<<endl;
	for(auto x:pos){
		int p=x;
		int cnt=0;
		while(p>=0&&s[p]=='>'){
			++cnt;
			--p;
		}
		if(pre>cnt)--cnt;
		else ans-=pre;
		ans+=(cnt*(cnt+1))/2;
		//cout<<cnt<<"\n";
		p=x+1;
		cnt=0;
		while(p<n&&s[p]=='<'){
			++cnt;
			++p;
		}
		//cout<<cnt<<"\n";
		ans+=(cnt*(cnt+1))/2;
		//cout<<ans<<endl;
		pre=cnt;
	}
	cout<<ans<<"\n";
}
#undef int

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
