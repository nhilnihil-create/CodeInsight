
// Problem : C - A x B + C
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


#include<bits/stdc++.h>
using namespace std;


#define sc(ar,n) for(int pen=0;pen<n;pen++){ cin>>ar[pen];}
#define pr(ar,n) for(int pen=0;pen<n;pen++){ cout<<ar[pen]<<" ";} cout<<endl;
#define mem(ar,x) memset(ar,x,sizeof(ar))
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define rt return 0;
#define ct continue;
#define pb push_back
#define ll long long int
#define ff first
#define ss second
#define mod 1000000007
#define maxn 1000003
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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



int main(){
	
	fastio;
	
	ll n,ans=0;
	cin>>n;
	
	for(int i=1;i  < n ;i++){
	 ans += (n-1)/i;
	}
	cout<<ans;
	
	}


	
	
	
	

