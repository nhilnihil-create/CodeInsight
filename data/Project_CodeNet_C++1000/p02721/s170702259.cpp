#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=200005;
//i_am_noob
int n,k,c,cnt1[maxn],cnt2[maxn];
string str;
bool b1[maxn]={false},b2[maxn]={false};
vector<int> vec1,vec2;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k >> c >> str;
	rep(n) if(str[i]=='o'){
		if(vec1.empty()) vec1.pb(i);
		else if(i-vec1.back()>c) vec1.pb(i);
	}
	rep3(i,n-1,0) if(str[i]=='o'){
		if(vec2.empty()) vec2.pb(i);
		else if(vec2.back()-i>c) vec2.pb(i);
	}
	rep(sz(vec1)) b1[vec1[i]]=true;
	rep(sz(vec2)) b2[vec2[i]]=true;
	cnt1[0]=0;
	rep(n) cnt1[i+1]=cnt1[i]+b1[i];
	cnt2[0]=0;
	rep(n) cnt2[i+1]=cnt2[i]+b2[n-1-i];
	rep(n) if(cnt1[i]+cnt2[n-1-i]<k) print1(i+1);
	return 0;
}