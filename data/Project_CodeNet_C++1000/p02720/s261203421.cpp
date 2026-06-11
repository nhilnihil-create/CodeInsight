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

ll n;
ll ans;
ll c=1;

bool f(ll num, ll digit){
	if(digit==(ll)log10(num)+1){
		if(n==c){
			ans = num;
			return true;
		}else{
			c++;
			return false;
		}
	}
	
	int rnum = num%10;
	for(int i = max(rnum-1,0); i<=min(rnum+1,9); i++){
		if(f(num*10 + i,digit)) return true;
	}
	return false;
}

int main(){
	cin >> n;
	
	ll digit=1;
	while(true){
		bool res = false;
		for(int i=1; i<=9; i++){
			res = f(i,digit);
			if(res) break;
		}
		if(res)break;
		digit++;
	}
	
	cout << ans << endl;
	
	return 0;
}