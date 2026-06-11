#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ub upper_bound
#define lb lower_bound
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
void input(vector<int>&a,int n)
{
   rep(i,0,n-1)
   cin>>a[i];
}

void solve()
{
  string s; cin>>s; 
  vector<int>f(27,0);
  for(int i=0;i<=3;i++)
  {
  	int i1=s[i]-65; f[i1]++; 
  }
  int c2=0; 
  for(auto i:f)
  {
  	if(i==2) c2++;
  }
  if(c2==2) cout<<"Yes\n";
  else cout<<"No\n"; return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  while(t--)
  {
	 solve();
  }
  return 0;
}


