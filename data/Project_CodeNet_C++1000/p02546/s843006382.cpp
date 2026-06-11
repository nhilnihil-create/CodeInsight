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
#define F first
#define S second
#define MP(x,y) make_pair(x,y)
#define rt return
#define br break
#define ct continue
#define elif else if
#define ii pair<ll,ll>
#define vecin(a,n,index) for(int i=index;i<n;i++)cin>>a[i]
#define vecout(a,n,index) for(int i=index;i<n;i++)cout<<a[i]<<" ";cout<<endl;
//ll mod = 1000000007;
void solve() {
	string s;
	cin >> s;
	if (s[s.length() - 1] == 's')cout << s << "es" << endl;
	else cout << s << "s" << endl;
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