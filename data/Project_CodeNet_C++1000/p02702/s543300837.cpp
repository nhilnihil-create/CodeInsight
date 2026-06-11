#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	string s;
	cin >> s;
	int n = s.size();
	
	vector<int> sp(n+1);
	
	int num = 0;
	int ten = 10;
	sp[n] = 0;
	for(int i=n-1; i>=0; i--){
		num += ten*(s[i]-'0')%2019;
		num %= 2019;
		sp[i] = num;
		ten = (ten*10)%2019;
	}
	
	int a[2019]={};
	REP(i,n+1){
		a[sp[i]]++;
	}
	
	ll ans = 0;
	REP(i,2019){
		ll b = ((ll)a[i]*(a[i]-1))/2;
		ans += b;
	}
	
	cout << ans << endl;
	
	
	return 0;
}