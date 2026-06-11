#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
#define lb long double
#define pb push_back
#define loop(i,start,n) for(ll i=start;i<n;i++)
#define rloop(i,n,start)for(ll i=n;i>=start;i--)
#define mod 1000000007
#define endl "\n"
#define INF     1e15
#define NEG_INF -1e15
#define pll pair<ll,ll>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
//using namespace __gnu_pbds;
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
ll tree1[10000000], tree2[10000000];
ll query(ll tree[], ll l, ll r, ll L, ll R, ll node){   
    
    if(l <= L && R <= r){
        return tree[node];
    }
    else if(r < L || R < l)
        return NEG_INF;
    else{
        ll mid;
        mid=(L + R) / 2;
        return max(query(tree, l, r, L, mid, node * 2), query(tree, l, r, mid + 1, R, node * 2 + 1));
    }
}

ll value;
void update(ll tree[], ll pos, ll L, ll R, ll node){   
    //cout<<L<<" "<<R<<" "<<pos<<endl;
    if(L == R && R == pos){
        tree[node] = value;
        return ;
    }
    else{   
        ll mid;
        mid=(L + R) / 2;
        if(pos <= mid)
            update(tree, pos, L, mid, node * 2);
        else
            update(tree, pos, mid + 1, R, node * 2 + 1);
        
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        return ;
    }
}
int main(){
	IOS;
	loop(i, 0, 4000000)
		tree1[i] = NEG_INF, tree2[i] = NEG_INF;
	ll n;
	cin >> n;
	pll a[n + 1];
	loop(i, 1, n + 1){
		cin >> a[i].x >> a[i].y;	
	}

	sort(a + 1, a + n + 1);
	loop(i, 1, n + 1){
		value = a[i].x + a[i].y;
		update(tree1, i, 1, n, 1);
		
		value = a[i].x - a[i].y;
		update(tree2, i, 1, n, 1);
	}

	ll ans = 0;
	loop(i, 1, n + 1){
		ll temp = query(tree1, i, n, 1, n , 1);
		ans = max(ans, temp - a[i].x - a[i].y);

		temp = query(tree2, i, n, 1, n, 1);
		ans = max(ans, temp + a[i].y - a[i].x); 
	} 

	cout << ans << endl;
}