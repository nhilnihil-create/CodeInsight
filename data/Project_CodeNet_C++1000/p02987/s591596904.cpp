#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define num(a) a-'0'
#define charr(a) (a - 'A' + 1)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define maxs(a,b) if(b>a)a=b
#define mins(a,b) if(b<a)a=b
#define bin1(a) __builtin_popcount(a)
#define debug(x) cerr<<"["<<#x<<":"<<x<<"] "
#define debug2(a,b) debug(a);debug(b)
#define debug3(a,b,c) debug2(a,b);debug(c)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define print(arr) for(auto it = arr.begin();it < arr.end();it ++){cout << *it << " ";}cout << ln;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define all(a) (a).begin(), (a).end()
#define vi vector<long long>
#define v vector
#define p pair
#define pii p<int,int>
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define ln "\n"
typedef long double ld;
typedef double d;
using namespace std;
using namespace __gnu_pbds;
int modF=1e9+7;
int inf=1e18+5;

/*OUTPUT

*/

void solve(){
	string s;
	cin>>s;
	vi fr(26,0);
	rep(i,0,4){
		fr[s[i]-'A']++;
	}
	bool pos=true;
	rep(i,0,26){
		if(fr[i]!=0 && fr[i]!=2){
			pos=false;
		}
	}
	if(pos){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}

signed main(){
	boost_io;
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}