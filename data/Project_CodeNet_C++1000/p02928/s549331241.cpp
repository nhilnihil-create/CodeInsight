#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	ll n,k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<ll> lt(n);
	rep(i,n) lt[i] = 0;
	rep(i,n) {
		rep(j,n) {
			if(i==j) continue;
			if(a[i] > a[j]) lt[i]++;
		}
	}
	vector<ll> lta(n);
	rep(i,n) lta[i] = 0;
	rep(i,n) for(int j=i+1; j<n; j++) {
		if(a[i] > a[j]) lta[i]++;
	}
	vector<ll> ans(n);
	rep(i,n) ans[i] = 0;
	rep(i,n) {
		ll temp = lt[i];
		if(k%2==0) {
			temp *= k/2;
			temp %= MOD;
			temp *= k-1;
			temp %= MOD;
		}
		else {
			temp *= (k-1)/2;
			temp %= MOD;
			temp *= k;
			temp %= MOD;
		}
		ans[i] += temp;
		ans[i] %= MOD;
		ans[i] += lta[i] * k;
		ans[i] %= MOD;
	}
	ll answ = 0;
	rep(i,n) {
		answ += ans[i];
		answ %= MOD;
	}
	cout << answ << endl;


  return 0;
}
