#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

void fin(bool b){
	if(b) cout << "Yes" << endl;
	else cout << "No" << endl;
	exit(0);
}

int main(){
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	a--; b--; c--; d--;
	string s;
	cin >> s;
	if(c < b){
		rep2(i, a, c){
			if(s.at(i) == '#' && s.at(i+1) == '#') fin(false);
		}
		rep2(i, b, d){
			if(s.at(i) == '#' && s.at(i+1) == '#') fin(false);
		}
	}else if(c < d){
		rep2(i, a, d){
			if(s.at(i) == '#' && s.at(i+1) == '#') fin(false);
		}
	}else{
		bool flag = false;
		rep2(i, a, c){
			if(s.at(i) == '#' && s.at(i+1) == '#') fin(false);
			if(b <= i && i <= d){
				if(s.at(i) == '.' && s.at(i-1) == '.' && s.at(i+1) == '.') flag = true;
			}
		}
		if(flag == false) fin(false);
	}
	cout << "Yes" << endl;
	return 0;
}