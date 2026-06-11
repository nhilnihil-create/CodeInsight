#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORit(it,a) for(auto it=a.begin();it!=a.end();it++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define vec vector
#define vi vec<int>
#define vll vec<ll>
#define pb push_back
#define pp pop_back
#define all(x) x.begin(),x.end()
#define testcases ll t;cin>>t;while(t--)
#define mem(a,k) memset(a,k,sizeof(a))
#define FF first
#define SS second
#define MP(x,y) make_pair(x,y)
#define rt return
#define br break
#define ct continue
#define elif else if
#define ii pair<int,int>
#define vecin(a,n,index) for(int i=index;i<n;i++)cin>>a[i]
#define vecout(a,n,index) for(int i=index;i<n;i++)cout<<a[i]<<" ";cout<<endl;
//ll mod = 1000000007;
int fun(int k) {
	int div = 1;
	FOR(i, 2, int(sqrt(k)) + 1) {
		if (k % i == 0) {
			int cnt = 0;
			while (k % i == 0) {cnt++; k /= i;}
			div = div * (cnt + 1);
		}
	}

	if (k > 1) {div = div * (2);}
	rt div;
}
void solve() {
	int n;
	cin >> n;
	int ans = 0;
	FOR(c, 1, n) {
		int k = n - c;
		ans += (fun(k));
	}
	cout << ans << endl;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	// START FROM HERE :)
	solve();
}