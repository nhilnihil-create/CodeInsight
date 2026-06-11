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
	int n,m;
	cin >> n >> m;
	vector<bool> broken(n,false);
	int a;
	REP(i,m){
		cin >> a;
		broken[a] = true;
	}
	ll modnum = 1000000007;
	vector<ll> step(n+1);
	
	step[0] = 1;
	for(int i=1; i<=n; ++i){
		if(broken[i]) continue;
		ll count = 0;
		if(i-1 >= 0 && !broken[i-1]){
			count += step[i-1];
		}
		if(i-2 >= 0 && !broken[i-2]){
			count += step[i-2];
		}
		count = count%modnum;
		step[i] = count;
	}
	
	cout << step[n] << endl;
	
	return 0;
}