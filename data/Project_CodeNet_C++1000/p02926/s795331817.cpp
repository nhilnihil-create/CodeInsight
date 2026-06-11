#include <bits/stdc++.h>
using namespace std;
 
#define fastIO \
ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define ll long long
#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int> 

bool compare(const pii &a, const pii &b){
	return atan2(a.ss,a.ff) < atan2(b.ss,b.ff);
}
 
long double dis(pair<ll,ll> a, pair<ll,ll> b){
	long double x = abs(a.ff-b.ff), y = abs(a.ss-b.ss);
	return (x*x + y*y);
}
 
int main(){
	int n;
	cin >> n;
	vector <pii> v(n);
	for(int i=0;i<n;i++)	cin >> v[i].ff >> v[i].ss;
	sort(v.begin(), v.end(), compare);
	vector < pair<ll,ll> > prefix(2*n);
	prefix[0] = v[0];
	for(int i=1;i<n;i++)
		prefix[i] = mp(prefix[i-1].ff+v[i].ff, prefix[i-1].ss+v[i].ss);
	for(int i=n;i<2*n;i++)	
		prefix[i] = mp(prefix[i-1].ff+v[i%n].ff, prefix[i-1].ss+v[i%n].ss);
	long double ans = 0.0;
	for(int i=0;i<n;i++)
		for(int j=i;j<i+n;j++)
			ans = max(ans, dis(prefix[j], i>0?prefix[i-1]:mp(0LL,0LL)));
	cout << fixed << setprecision(50) << sqrt(ans) << endl;
	return 0;
}