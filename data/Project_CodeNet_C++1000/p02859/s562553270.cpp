#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4.2")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define PB push_back
#define PI acos(-1)
#define all(x) x.begin(),x.end()
#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define vb vector<bool>
#define vvi vector<vector<ll> >
#define vvii vector<vii>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read(x) long long x;cin>>x;
#define FOR(a,b,c,d) for(int a=b;a<=c;a+=d)
#define MP make_pair
#define F first
#define AS assign
#define S second
#define debug(x) cout<<(#x)<<": "<<(x)<<"\n"
#define SZ(x) x.size()
#define mod 1000000007
#define lg2(x) 63-(__builtin_ctzll(x))
#define RZ resize
#define IN insert
#define X real()
#define Y imag()
#define FBO find_by_order
#define OFK order_of_key
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
typedef unsigned long long ull;
typedef long double d64;
typedef complex<d64>P;
ll modpow(int a,int b,int m){if(!b)return 1%m;ll u=modpow(a,b/2,m);u=(u*u)%m;if(b&1)u=(u*a)%m;return u;}



int main(){
read(n);
cout<<n*n;
return 0;
}


