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
	
	
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	REP(i,N) cin >> A[i];
	REP(i,N) A[i]--;

	vector<ll> memo(N, -1);
	memo[0] = 0;

	ll p=0;
	for(ll i=1; i<=K; i++){
		if(memo[A[p]] == -1){
			memo[A[p]] = i;
		}else{
			ll loop = i - memo[A[p]];
			if(i+loop < K){
				i += loop*((K-i)/loop);
			}
		}
		p = A[p];
	}
	cout << (p+1) << endl;
	
	return 0;

abnormal:
	cout << "No" << endl;
	return 0;
}