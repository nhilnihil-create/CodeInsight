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
	
	
	ll X,N;
	vector<ll> p(100,-1);
	cin >> X >> N;
	REP(i,N) cin >> p[i];
	if(N==0){
		cout << X << endl;
		return 0;
	}
	ll test = 0;
	while(true){
		ll ret = X - test;
		bool check = false;
		REP(i,N) if(ret==p[i]) check = true;
		if(!check){
			cout << ret << endl;
			return 0;
		}
		ret = X + test;
		check = false;
		REP(i,N) if(ret==p[i]) check = true;
		if(!check){
			cout << ret << endl;
			return 0;
		}
		test++;
	}
	
	return 0;
}