#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(),v.end()

int main(){
	int n, q; cin >> n >> q;
	fenwick_tree<ll> fw(n);
	int a;
	REP(i,n){
		cin >> a;
		fw.add(i,a);
	}
	while(q--){
		int t, x, y;
		cin >> t >> x >> y;
		if(t==0)
			fw.add(x,y);
		else
			cout << fw.sum(x,y) << endl;
	}
	return 0;
}