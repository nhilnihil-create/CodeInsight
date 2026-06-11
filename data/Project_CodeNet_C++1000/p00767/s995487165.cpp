//#include"bits/stdc++.h"
#include<iostream>
#include<ostream>
#include<vector>
#include<string>
#include<algorithm>

#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)



using namespace std;
using ll = long long;



void solve();

int main() {

   solve();
   return 0;

}

void solve() {

	ll w, h, l;
	vector<pair<ll, pair<ll, ll>>> v;

	FOR(h_, 1, 200) {
		FOR(w_, h_ + 1, 200) {
			v.push_back(make_pair(h_*h_ + w_*w_, make_pair(h_, w_)));
		}
	}
	sort(v.begin(), v.end());

	while (cin >> h>>w,h) {
		l = h*h + w*w;
		for (vector<pair<ll, pair<ll, ll>>>::iterator it = v.begin(); it < v.end(); it++) {
			if (it->first == l && it->second.first == h) {
				cout << (it+1)->second.first << ' ' << (it+1)->second.second << endl;
				break;
			}
		}

	}
}