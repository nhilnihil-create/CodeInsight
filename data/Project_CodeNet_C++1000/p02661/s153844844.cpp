#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	REP(i,n) cin >> a[i] >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	if(n%2){
		cout << b[n/2]-a[n/2]+1 << endl;
	}else{
		cout << b[n/2-1]+b[n/2]-(a[n/2-1]+a[n/2])+1 << endl;
	}
	
	return 0;
}