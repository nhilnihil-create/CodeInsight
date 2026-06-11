#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
typedef long long ll;

int main(){
	ll n;
	string s;
	cin >> n >> s;
	
	ll r=0,g=0,b=0;
	REP(i,n){
		if(s[i]=='R') r++;
		if(s[i]=='G') g++;
		if(s[i]=='B') b++;
	}
	ll ans = r*g*b;
	
	
	
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int k = 2*j - i;
			if(k > n) break;
			if(s[i-1]!=s[j-1] && s[j-1]!=s[k-1] && s[k-1]!=s[i-1]) ans--; 
		}
	}
	
	cout << ans << endl;
	
	return 0;
}