#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

ll fact_two[1111111];
ll initialised = false;
ll comb_mod_two(ll n, ll r){
	if(n < r)return 0;
	if(!initialised){
		for(int i = 1;i < 1111111;i++){
			fact_two[i] = fact_two[i-1];
			ll now = i;
			while(now % 2 == 0){
				fact_two[i]++;
				now /= 2;
			}
		}
		initialised = true;
	}

	ll a = fact_two[n];
	ll b = fact_two[n-r] + fact_two[r];
	if(a > b)return 0;
	else return 1;
}

bool seica(vector<ll> v){
	ll n = v.size();
	ll cou = 0;
	REP(i, n){
		cou += v[i] * comb_mod_two(n-1, i);
		cou %= 2;
	}
	return cou;
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	ll n;cin >> n;
	string str;cin >> str;

	vector<ll> v;
	REP(i, n)v.PB(str[i] - '1');

	if(seica(v)){
		cout << 1 << endl;
		return 0;
	}

	REP(i, n){
		if(v[i] == 1){
			cout << 0 << endl;
			return 0;
		}
		v[i] /= 2;
	}

	if(seica(v)){
		cout << 2 << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}
