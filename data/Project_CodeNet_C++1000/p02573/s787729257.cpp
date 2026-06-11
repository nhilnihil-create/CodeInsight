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
	
	
	ll N, M;
	cin >> N >> M;
	vector< list<ll> > l(N+1, list<ll>());
	REP(i,M) {
		ll A,B;
		cin >> A >> B;
		l[A].push_back(B);
		l[B].push_back(A);
	}

	vector<ll> memo(N+1, 0);
	ll ret = 0;

	REP(i, N+1){
		ll test = 0;
		queue<ll> que;
		que.push(i);
		while(!que.empty()){
			ll n = que.front();
			que.pop();

			if(memo[n] != 0) continue;
			memo[n] = 1;
			test++;
			for(list<ll>::iterator it = l[n].begin(); it != l[n].end(); it++){
				que.push(*it);
			}
		}
		ret = max(ret, test);
	}
	cout << ret << endl;
	
	return 0;

abnormal:
	cout << "No" << endl;
	return 0;
}