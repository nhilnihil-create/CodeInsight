#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
using ull = unsigned long long; 
const ull MOD{(1ull<<61)-1};

struct RollingHash{
	const ull m30{(1ull<<30)-1};
	const ull m31{(1ull<<31)-1};
	const ull MOD{(1ull<<61)-1};
	const ull pos{MOD*7};
	ull base;
	vector<ull> powmemo;
	vector<ull> hash;
	
	RollingHash(string s, ull b) : base(b), powmemo(s.size()+1), hash(s.size()+1){
		powmemo.at(0) = 1;
		for(int i=1; i<powmemo.size(); i++){
			powmemo.at(i) = calmod(mul(powmemo.at(i-1),base));
		}
		for(int i=0; i<s.size(); i++){
			hash.at(i+1) = calmod(mul(hash.at(i),base)+s.at(i));
		}
	}
	ull slice(int begin, int length){
		return calmod( hash.at(begin+length) + pos - mul( hash.at(begin),powmemo.at(length) ) );
	}
	ull mul(ull l, ull r){
		ull lu{l>>31};
		ull ld{l&m31};
		ull ru{r>>31};
		ull rd{r&m31};
		ull mid{ld*ru + lu*rd};
		return ( ((lu*ru)<<1) + ld*rd + ((mid&m30)<<31) + (mid>>30) );
	}
	ull calmod(ull val){
		val = (val&MOD) + (val>>61);
		if(val>=MOD) val -= MOD;
		return val;
	}
};

bool isok(RollingHash &rh, int m, int n){
	for(int i=0; i+m<=n; i++){
		for(int j=i+m; j+m<=n; j++){
			if(rh.slice(i,m)==rh.slice(j,m)){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int n;
	string s; cin>>n>>s;
	RollingHash rh(s,257);
	int m=n/2+1;
	int ok = 0, ng = n;
	while(abs(ok-ng)>1){
		auto mid = (ok+ng)/2;
		(isok(rh,mid,n)?ok:ng) = mid;
	}
	cout << ok << endl;
}