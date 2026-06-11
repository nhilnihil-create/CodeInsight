#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vs = vector<string>;
using pll = pair<ll,ll>;
using vpl = vector<pll>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;

#define R(a,i) for(ll a=0; a < (i); (a)++)
#define FOR(a,i,j) for(ll a=(i); a < (j); (a)++)
#define RD(a,i) for(ll a=(i)-1; (a) >= 0; (a)--)
#define FORD(a,i,j) for(ll a=(j)-1; (a) >= (i); (a)--)

#define xx first
#define yy second
#define pb push_back

#define all(X) begin(X),end(X)
#define rall(X) rbegin(X),rend(X)
#define sz(X) (X).size()

#define DBG 0
#define TR(X) {if(DBG) cerr << (#X) << " = " << (X) << "\n";}
#define hline {if(DBG) cerr << "----------------------------------------------------------------------" << "\n";}
#define PK(X) {if(DBG) cerr << (X) << "\n";}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N;
	cin >> N;

	ll search = 0;
	ll combi = 0;
	vl ai(N);
	FOR(i,0,N) {
		cin >> ai[i];
		combi ^= ai[i];
	}

	FOR(i,0,N){
		ai[i] &= ~ combi;
	}

	ll taken = 0;
	FORD(i,0,61){
		ll idx = -1;
		FOR(j,taken,N){
			if( ai[j] & (1LL << i) ) {
				if(idx == -1){
					idx = j;
					swap(ai[j], ai[taken]);
					taken++;
					break;
				}
			}
		}
		if(idx != -1)
			TR(bitset<64>(ai[taken-1]));
		FOR(j,0,N){
			if( ai[j] & (1LL << i) ) {
				if(idx != -1 && j != taken - 1){
					ai[j] ^= ai[taken-1];
				}
			}
		}
	}

	FOR(i,0,N){
		TR(bitset<64>(ai[i]));
		search ^= ai[i];
	}

	TR(bitset<64>(combi));

	cout << search * 2 + combi << endl;
}
