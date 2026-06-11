#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef pair<ll,ll> prl;
typedef vector<ll> vcl;
typedef map<ll,ll> mapl;
typedef unordered_map<ll,ll> umap;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;

//Union_Find
const ll max_n = 1e6+5;
ll ufpar[max_n], ufrank[max_n], ufnum[max_n];
//初期化忘れるな！
void init(ll n){
	rep(ii,0,n){
		ufpar[ii] = ii;
		ufrank[ii] = 0;
		ufnum[ii] = 1;
	}
}
ll ufind(ll x){
	if(ufpar[x] == x) {
		return x;
	} else {
		ll umm = ufind(ufpar[x]);
		return ufpar[x] = umm;
	}
}
bool unite(ll x, ll y){
	x = ufind(x);
	y = ufind(y);
	if(x == y) return false;
	if(ufrank[x] < ufrank[y]) swap(x,y);
	if(ufrank[x] == ufrank[y]) ufrank[y]++;
	ufpar[y] = x;
	ufnum[x] += ufnum[y];
	ufnum[y] = 0;
	return true;
}
//xとyが同じ連結成分か
bool usame(ll x, ll y){
	return ufind(x) == ufind(y);
}
//xを含む連結成分のサイズ
ll usz(ll x){
	return ufnum[ufind(x)];
}

int main() {
    // your code goes here
    ll n,q;
    cin >> n >> q;
    init(n);
    rep(r,1,q){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a==0) unite(b,c);
        else cout << usame(b,c) << endl;
    }
    return 0;
}