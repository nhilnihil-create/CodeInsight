#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL endl
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define deb(x) cout << #x": " << (x) << endl;
const lli N = 1e7;
const lli INF = 1e18;
const lli mod = 1e9+7;

// ---- コーディングはここから！ ('-')7



int main(){_
	int n; cin>>n;
	vl v(n);
	fore(i,0,n)cin>>v[i];
	lli d=1000, a = 0, mx = 1000;
	fore(i,0,n-1){
		if(v[i]<=v[i+1]){
			lli x = d/v[i];
			d-=x*v[i];
			a+=x;
		}
		if(v[i]>v[i+1]){
			lli x = a*v[i];
			d+=x;
			a=0;
		}
		mx = max(d,mx);
	}
	if(v[n-1]>=v[n-2]){
		lli x = a*v[n-1];
		d+=x;
		a=0;
		mx = max(d,mx);
	}
	cout<<mx<<ENDL;

}
