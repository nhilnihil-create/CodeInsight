#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
ll f(ll i,ll j){
	ll x=2,p=1;
	while(1){
		if((i%x)!=(j%x))return p;
		x*=2;
		p++;
	}
}
int main(){
	ll N;
	cin >> N;
	FOR(i,1,N){
		FOR(j,i+1,N+1){
			cout << f(i,j) << " ";
		}
		cout << "\n";
	}
}
