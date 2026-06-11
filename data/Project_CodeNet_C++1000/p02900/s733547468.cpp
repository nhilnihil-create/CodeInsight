#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;

vector<P> prime_factorize(ll N){
	vector<P> ans;
	for(ll a = 2; a*a <= N; a++){
		if(N%a == 0){
			ll ex = 0;
			while(N%a == 0){
				ex++;
				N /= a;
			}
			ans.push_back(P(a, ex));
		}
	}
	if(N != 1) ans.push_back(P(N, 1));
	return ans;
}


int main(){
    ll A, B; scanf("%lld %lld", &A, &B);
    ll g = __gcd(A, B);
    auto vec = prime_factorize(g);
    printf("%d\n", int(vec.size()) + 1);
}