#include<bits/stdc++.h>
#include<climits>

using namespace std;

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
#define fie(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define mod 998244353
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define ll long long
#define lld long long int
#define ALL(x) (x).begin(),(x).end()

typedef vector<lld> vi;
typedef vector<vector<lld>> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<lld, lld>> vpi;
typedef long long LL;


int main() {
	fast;
	cin.tie(0);
	lld n, i;
	cin >> n;
	lld x[n], y[n];
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	set<lld> s, ss;
	for (i = 0; i < n; i++) {
		s.insert(x[i] + y[i]);
		ss.insert(x[i] - y[i]);
	}

	lld ans1 = (*prev(s.end())) - (*s.begin());
	lld ans2 = (*prev(ss.end())) - (*ss.begin());
	cout << max(ans1, ans2) << endl;
}






