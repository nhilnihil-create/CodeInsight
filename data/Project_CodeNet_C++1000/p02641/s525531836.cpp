#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

int t, n;
vector<pair<double,double>> v;

double deltaT(double r) {
	
	double mn=DBL_MAX;
	
	for(int i=0; i<n-1; ++i) mn=min(mn,(r/v[i].f)+((t-r)/v[i].s));

	double dude = (r/v[n-1].f)+((t-r)/v[n-1].s);
	
	return (mn-dude)*3600;
}

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	//ofstream cout ("C_output.txt");
	//ifstream cin ("fileName.txt");
 	
	int x, n;
	cin >> x >> n;
	
	vi v(n);
	for(int i=0; i<n; ++i) cin >> v[i];
	
	sort(v.begin(), v.end());
	
	if(!binary_search(v.begin(), v.end(), x)) cout << x << "\n";
	else {
		
		for(int i=1; ; ++i) {
			if(!binary_search(v.begin(), v.end(), x-i)) {
				cout << x-i << "\n";
				return 0;
			}
			else if(!binary_search(v.begin(), v.end(), x+i)) {
				cout << x+i << "\n";
				return 0;
			}
		} 
	}
	
	return 0;
}
