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
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int n;
vector<string> ans;

void dfs(string s){
	if(s.size()==n){
		ans.push_back(s);
		return;
	}
	
	set<char> cset;
	for(auto x:s) cset.insert(x);
	
	char c;
	for(auto x: cset){
		dfs(s+x);
		c = x;
	}
	c = (char)((int)c+1);
	dfs(s+c);
	
	return;
}

int main(){
	cin >> n;
	
	dfs("a");
	
	for(auto s:ans){
		cout << s << endl;
	}
	
	return 0;
}