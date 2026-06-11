#pragma GCC optimize("O2")
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<cmath>
#include<climits>
#include<random>
#include <iomanip>
#include <bitset>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

/////////////////////////////////////////////

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

////////////////////////////////

#define int long long

void solve(){

	int n;
	cin>>n;
	int a[n];
	int b[n];

	for(int i = 0 ; i < n ; ++i)
		cin>>a[i]>>b[i];

	sort(a ,a + n);
	sort(b , b + n);
	int ans = 0;
	if(n&1)
		ans = b[n/2] - a[n/2] + 1;
	else ans = (b[(n-1)/2] + b[n/2] - a[(n-1)/2] - a[n/2]) + 1;


	cout<<ans<<endl;
}

signed main(){

	int t = 1;
	//cin>>t;
	while(t--)
		solve();
}