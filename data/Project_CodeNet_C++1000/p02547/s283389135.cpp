#include<bits/stdc++.h>
using namespace std;

#define pi 3.141592653589
#define MOD 1000000007
#define to() int t; cin>>t; while(t--)
#define pb push_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define si(s) s.size()
#define fori(it,v) for(it=v.begin();it!=v.end(); it++)
#define for1(low,high,k) for(int i=low;i<high;i+=k)
#define for11(low,high,k) for(int j=low;j<high;j+=k)
#define for2(low,high,k) for(int i=low;i<=high;i+=k)
#define rev(high,low,k)  for(int i=high;i>=low ;i-=k)
#define all(x) x.begin(), x.end()
#define fil(x,i) memset(x,i,sizeof(x));
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

void i_o() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
}

int main()
{
	boost; i_o();
	int n; cin >> n;
	std::vector<pair<int, int> > v(n);
	for1(0, n, 1) cin >> v[i].ff >> v[i].ss;
	bool f = false;
	for1(0, n - 2, 1) {
		if (v[i].ff == v[i].ss && v[i + 1].ff == v[i + 1].ss && v[i + 2].ff == v[i + 2].ss) f = true;
	}
	if (f) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
