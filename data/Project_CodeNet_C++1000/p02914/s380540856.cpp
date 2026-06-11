// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")



#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define Find order_of_key
// #define at find_by_order
#define x first
#define y second
#define ll long long
#define lll __int128
#define ull unsigned long long
#define ulll unsigned __int128
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define gu getchar_unlocked()
#define pu putchar_unlocked()
#define all(x) x.begin(),x.end()
#define endl '\n'

struct maxxor {
	ll best[64], msb;
	maxxor() { memset(best, -1, sizeof best); }
	void add(ll x) { 
		while(x > 0) {
			msb = 63 - __builtin_clzll(x);
			if(best[msb] == -1) {
				best[msb] = x; break;
			} else x = x ^ best[msb]; 
		}
	}
	ll get(ll ret = 0) {
		for(ll i = 63; i >= 0; i--) {
			if(best[i] != -1) 
				ret = max(ret, ret ^ best[i]);
		} return ret;
	}
} ds;

const int maxn=100010;
ll a[maxn];
int n;
int main()
{
	ll x=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x^=a[i];
	}
	ll an=0;
	for(int j=0;j<64;j++){
		if(x&(1LL<<j)){
			an+=(1LL<<j);
			for(int i=0;i<n;i++){
				if(a[i]&(1LL<<j)){
					a[i]^=(1LL<<j);
				}
			}
		}
	}
	for(int i=0;i<n;i++)ds.add(a[i]);
	cout<<an+ds.get()*2LL<<endl;
	return 0;
}