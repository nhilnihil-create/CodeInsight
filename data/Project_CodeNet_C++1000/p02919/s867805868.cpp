#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

///////////////////////////





int main() {

	ll N;
	ll P[MAX];

	cin >> N;
	repn(i, N) cin >> P[i];

	ll Pinv[MAX];

	repn(i, N) Pinv[P[i]] = i;

	

	multiset<ll> st = {0,0,N+1,N+1};

	ll ans = 0;


	for (int i = N; i > 0; i--) {
		auto itr=st.insert(Pinv[i]);
		
		ll n = Pinv[i];

		ll b  =*--itr;
		ll a = *--itr;
		ll c = *++(++(++itr));
		ll d = *++itr;
		

		ans += ((n - b)*(d - c) + (b - a)*(c - n))*i;

		

	}

	cout << ans;

	





	system("PAUSE");
}