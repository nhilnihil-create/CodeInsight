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
	cin >> N;
	vector<ll> A(N,0);
	REP(i,N){
		cin >> A[i];
	}
	sort(A.begin(), A.end(), greater<ll>());
	ll ans = A[0];
	for(int i=2; i<N; i++){
		ans += A[i/2];
	}
	cout << ans << endl;
	
	return 0;
}