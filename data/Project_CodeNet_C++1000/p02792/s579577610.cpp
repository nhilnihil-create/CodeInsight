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
	int N;
	cin >> N;
	
	int digit = log10(N) + 1;
	int x[10][10] = {};
	for(int i=1; i<=N; i++){
		string s = to_string(i);
		x[(int)(s[0]-'0')][(int)(s[s.size()-1]-'0')]++;
	}
	
	ll ans=0;
	REP(i,10){
		REP(j,10){
			if(i*j==0) continue;
			ans += x[i][j]*x[j][i];
		}
	}

	cout << ans << endl;
	
	return 0;
}