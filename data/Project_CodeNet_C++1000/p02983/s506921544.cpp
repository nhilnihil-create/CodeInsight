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
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll L,R;
	cin >> L >> R;
	
	ll ans=2019;
	for(ll i=L; i-L<2019 && i<=R; i++){
		for(ll j=i+1; j-i<2019 && j<=R; j++){
			chmin(ans, ((i%2019)*(j%2019))%2019);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}