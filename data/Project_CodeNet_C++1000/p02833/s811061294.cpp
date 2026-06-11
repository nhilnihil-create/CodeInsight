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
	ll n;
	cin >> n;
	
	if(n%2==1){
		cout << "0\n";
		return 0;
	}
	
	ll count5=0;
	
	ll i=5;
	while(n >= i){
		count5 += n/(i*2);
		i *= 5;
	}
	
	cout << count5 << endl;
	
	return 0;
}