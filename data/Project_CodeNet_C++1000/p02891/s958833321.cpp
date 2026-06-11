#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	string s; cin >> s;
	ll k; cin >> k;
	int n = s.size();
	ll ans = 0;
	int c=1;
	
	bool eql = true;
	rep(i,n-1)if(s[i]!=s[i+1])eql=false;
	if(eql){
		ll ans = (ll(n)*k/2);
		cout << ans << endl;
		return 0;
	}
	
	rep(i,n-1){
		if(s[i]!=s[i+1]){
			ans += c/2;
			c=1;
		}else c++;
	}
	ans += c/2;
	ans *= k;
	if(s[0]==s[n-1]){
		int a=1,b=1;
		for(int i=0; i<n; i++){
			if(s[i]==s[i+1])a++;
			else break;
		}
		for(int i=n-1; i>=0; i--){
			if(s[i]==s[i-1])b++;
			else break;
		}
		ans -= (a/2+b/2-(a+b)/2)*(k-1);
	}
	
	cout << ans << endl;
}
