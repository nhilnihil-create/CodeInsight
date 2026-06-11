#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, M, S, T;
vector<ll> to[100005];


int main(){
	cin >> N >> M;
	rep(i, M) {
		ll u, v;
		cin >> u >> v;
		u--;v--;
		to[u].push_back(v);
	}
	cin >> S >> T;
	S--;T--;


	//cost, pos, mod
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll> >, greater<tuple<ll, ll, ll> > > Q;
	//pos, mod
	map<pair<ll, ll>, ll >done;

	Q.push(make_tuple(0, S, 0));

	while(!Q.empty()) {
		tuple<ll, ll, ll> t = Q.top();
		ll pos = get<1>(t);
		ll mod = get<2>(t);
		ll cost = get<0> (t);
		Q.pop();

		if(done.count(make_pair(pos, mod)) != 0) continue;

		done[make_pair(pos, mod)] = cost;

		for(ll next: to[pos]) {
			tuple<ll, ll, ll> ntuple = make_tuple(cost + 1, next, (mod + 1) % 3);
			Q.push(ntuple);
		}
	}

	if(done[make_pair(T, 0)] == 0) {
		cout << -1 << endl;
	} else {
		cout << done[make_pair(T, 0)]/3L << endl;
	}
}
