#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
const int MOD = 998244353;

const int MAXN = 100005;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n,m; cin>>n>>m;
	string s(n,'.');
	forn(i,0,m){
		int p,x; cin>>p>>x; p--;
		if(s[p]!='.' && x!=s[p]-'0'){
			cout<<-1<<'\n';
			return 0;
		}
		
		s[p]='0'+x;
	}
	
	if(s[0]=='0' && n!=1){
		cout<<-1<<'\n';
		return 0;
	}
	
	forn(i,0,n){
		if(s[i]=='.'){
			if(i==0 && n!=1) s[i]='1';
			else s[i]='0';
		}
	}
	
	cout<<s<<'\n';
	
	return 0;
}
