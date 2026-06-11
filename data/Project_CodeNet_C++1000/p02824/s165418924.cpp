#include<bits/stdc++.h>
#define FOR(i,a,b)for(int i=(a),_b=(b);i<=_b;i++)
#define FORN(i,b,a)for(int i=(b);_a=(a);i>=_a;i--)
#define REP(i,n)for(ll i=0,_n=n;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define re return
#define vi vector<int>
#define pb push_back
#define si set<int>
#define in insert
#define fl float
#define db double
#define ld long double
#define X first
#define Y second
#define st string
#define ull unsigned long long
#define size(s) s.size()
using namespace std;
const int N = 100100;
int n;
ll m,v,p;
ll a[N];
ll pref[N];
int main()
{
	cin>>n>>m>>v>>p;
	int ans=0;
	REP(i,n)cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	REP(i,n)
		pref[i+1]=pref[i]+a[i];
	ans=p;
	for(int i=p;i<n;i++){
		if(a[i]+m<a[p-1])break;
		ll cur=v-(n-(i-p+1));
		if(cur<=0){
			ans++;
			continue;
		}
		if(cur*m<=(i-p+1)*(a[i]+m)-(pref[i]-pref[p-1]))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}