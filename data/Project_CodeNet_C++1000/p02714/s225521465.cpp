#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define mp make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(s) s.begin(),s.end()
#define vll vector<ll>
#define vi vector<int>
#define vpii vector<pii>
#define vpll vector<pll>
#define vull vector<ull>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define sz(x) x.size()
#define cinarr(n,a) for(int i = 0; i < n; i++) cin >> a[i];
#define coutarr(n,a) for(int i = 0; i < n; i++) cout << a[i] << (i+1==n?'\n':' ');
#define fori(i,a,b,x) for(int i = a; i <= b; i+=x)
#define ford(i,a,b,x) for(int i = a; i >= b; i-=x)
#define tc int tt; cin >> tt; for(int cs = 1; cs <= tt; cs++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define reset(x,y) memset(x,y,sizeof x);
#define EPS 1e-10
#define INF 2000000000
#define mod 1000000007
#define debug(val) cerr << "The value of " << #val << " is = " << val << endl;
#define testing cerr << "--------------------------\n";

ll pref[4005][105];
ll suf[10005][105];
map<char,string> tmp;
int main() {
	IOS
	tmp['R']="GB";
	tmp['G']="RB";
	tmp['B']="RG";
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i = 1; i<=n;i++) {
		for(auto x : tmp) {
			pref[i][x.fi]=pref[i-1][x.fi]+(s[i-1]==x.fi);
//			debug(pref[i][x.fi])
//			debug(x.fi)
		}
	}
//	testing
	for(int i = n; i>=1;i--) {
		for(auto x : tmp) {
			suf[i][x.fi]=suf[i+1][x.fi]+(s[i-1]==x.fi);
//			debug(suf[i][x.fi])
		}
	}
	ll res=0;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			char a=tmp[s[i-1]][0];
			char b=tmp[s[i-1]][1];
			ll haduh=(s[i-j-1]==a)*(suf[i+1][b]-suf[i+j][b]+suf[i+j+1][b]);
//			debug(haduh)
			ll haduh2=(s[i-j-1]==b)*(suf[i+1][a]-suf[i+j][a]+suf[i+j+1][a]);
//			debug(haduh2)
			res+=haduh;
			res+=haduh2;
//			testing
		}
	}
	cout<<res<<endl;
}
