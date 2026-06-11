#include <deque>
#include <cstdio>
using namespace std;
#define ll long long
int main(){
	ll N;
	scanf("%lld", &N);
	ll a[N], ps = 0, ns = 0;
	deque<ll> p, n;
	for (ll i = 0; i < N; i++){
		scanf("%lld", &a[i]);
		if (a[i] > 0){
			p.emplace_back(a[i]);
			ps += a[i];
		}else if (a[i] <= 0){
			n.emplace_back(a[i]);
			ns += a[i];
		}
	}
	if (p.empty()){
		ll ma = -2147483648, pos;
		for (ll i = 0; i < n.size(); i++){
			if (n[i] > ma){
				ma = n[i];
				pos = i;
			}
		}
		p.emplace_back(ma);
		n.erase(n.begin() + pos);
		ps += ma;
		ns -= ma;
	}
	if (n.empty()){
		ll mi = 2147483647, pos;
		for (ll i = 0; i < p.size(); i++){
			if (p[i] < mi){
				mi = p[i];
				pos = i;
			}
		}
		n.emplace_back(mi);
		p.erase(p.begin() + pos);
		ns += mi;
		ps -= mi;
	}
	printf("%lld\n", ps - ns);
	while (true){
		if (p.size() == 1 && n.size() == 1){
			printf("%lld %lld\n", p[0], n[0]);
			return 0;
		}
		if (n.size() == 1){
			printf("%lld %lld\n", n[0], p[0]);
			n.emplace_back(n[0] - p[0]);
			p.erase(p.begin());
			n.erase(n.begin());
		}else{
			printf("%lld %lld\n", p[0], n[0]);
			p.emplace_back(p[0] - n[0]);
			p.erase(p.begin());
			n.erase(n.begin());
		}
	}
}