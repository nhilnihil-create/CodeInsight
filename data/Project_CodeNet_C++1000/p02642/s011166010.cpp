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
	
	
	ll N;
	vector<ll> check(1000001,0);
	vector<ll> memo(1000001,0);
	cin >> N;
	vector<ll> A(N,0);
	REP(i,N) cin >> A[i];

	REP(i,N){
		memo[A[i]] ++;
		if(memo[A[i]] > 1) continue;
		for(int j=A[i]+A[i]; j<=1000000; j+=A[i]){
			check[j] = 1;
		}
	}
	ll ret = 0;
	REP(i,N){
		if(check[A[i]] == 0 && memo[A[i]] == 1) ret++;
	}
	cout << ret << endl;
	
	return 0;
}