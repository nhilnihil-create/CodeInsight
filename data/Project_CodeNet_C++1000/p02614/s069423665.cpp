#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(),(a).rend())
#define ll long long
#define pb(a) push_back(a)

#define PRINTV(v) {for(ll deB=0; deB<(v).size(); deB++){cout << (v)[deB] << " ";}cout << endl;}

int main(){
	
	
	ll H,W,K;
	char c[6][6];
	cin >> H >> W >> K;
	REP(h,H){
		REP(w,W){
			cin >> c[h][w];
		}
	}
	ll ans = 0;
	ll bit = 0x1 << (H+W);
	REP(i, bit){
		ll test = 0;
		REP(h,H){
			if((i >> h) & 0x1) continue;
			REP(w,W){
				if((i >> w+H) & 0x1) continue;
				if(c[h][w] == '#') test++;
			}
		}
		if(test == K) ans++;
	}
	cout << ans << endl;
	
	return 0;
}