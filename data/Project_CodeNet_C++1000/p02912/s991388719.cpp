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
// #define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define gu getchar_unlocked()
#define pu putchar_unlocked()
#define all(x) x.begin(),x.end()
#define endl '\n'
ll Pow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=(res*a);
		a=(a*a);
		b>>=1;
	}
	return res;
}
struct pii
{
	ll val;
	ll cnt;
	ll vv;
	pii(ll _a,ll _b){
		val=_a;
		cnt=_b;
		vv=0;
		if(cnt<=30){
			vv=val/(1LL<<cnt);
			// vv=round(val*1.0/(1LL<<cnt));
		}
	}
	bool operator<(const pii &a)const{
		// ll p=eval();
		// ll q=a.eval();
		ll p=vv-pii(val,cnt+1).vv;
		ll q=a.vv-pii(a.val,a.cnt+1).vv;
		if(p==q)return val<a.val;
		return p<q;
	}
};

int main()
{
	priority_queue<pii> q;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ll a;
		cin>>a;
		q.push(pii(a,0LL));
	}
	while(m--){
		pii x=q.top();
		q.pop();
		// cout<<x.val<<' '<<x.cnt+1<<' '<<x.vv<<endl;
		q.push(pii(x.val,x.cnt+1));
	}
	ll an=0;
	while(!q.empty()){
		pii x=q.top();
		q.pop();
		// ll vv=0;
		// if(x.cnt<=30){
		// 	vv=round(x.val*1.0/(1LL<<x.cnt));
		// }
		// cout<<x.val<<' '<<x.cnt<<endl;
		an+=x.vv;
	}
	cout<<an<<endl;
	return 0;
}