
// Problem : C - Walking Takahashi
// Contest : AtCoder - AtCoder Beginner Contest 175
// URL : https://atcoder.jp/contests/abc175/tasks/abc175_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define vi vector<ll>
#define vb vector<bool>
#define vp vector<pair<ll,ll>>
#define mod 1000000007
#define M_PI 3.14159265358979323846
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,b,a) for(ll i=b; i>=a ;--i)
#define vin(a) for(auto &i:a) cin>>i
#define mms(a,n) memset(a,n,sizeof(a))
#define fill(a,value) fill(a.begin(),a.end(),value)
#define all(a) a.begin(),a.end()
#define n_ones(x) __builtin_popcountll(x)
#define n_trailzero(x) __builtin_ctzll(x)
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define see(args...)                       \
{                                            \
    cerr<<"LINE "<<__LINE__;                 \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
    cerr<<endl;                              \
}
void err(istream_iterator<string> it){}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr<<' '<< *it << " = " << a ;
  err(++it, args...);
} 
template <typename T, typename U>inline void min_self(T &x, U y){if (y < x)x = y;}
template <typename T, typename U>inline void max_self(T &x, U y){if (x < y)x = y;}
template<class T1, class T2>ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<"["<<v.first<<", "<<v.second<<"]"; return out<<")"; }
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}

// cout << fixed << setprecision(10) << pi <<" "<<npi<<endl; 
// INT64_MAX
// transform(all(s), s.begin(), ::tolower);

ll XX[4] = {-1,0,1,0};
ll YY[4] = {0,-1,0,1};


void solve(){
    ll x,k,d;
    cin>>x>>k>>d;
    x = abs(x);
    ll times = x/d;
    x -= min(times,k)*d;
    k -= min(times,k);
    k%=2;
    if(k&1){
    	cout<<abs(x-d)<<endl;
    }
    else cout<<x<<endl;
    
    
	return;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}