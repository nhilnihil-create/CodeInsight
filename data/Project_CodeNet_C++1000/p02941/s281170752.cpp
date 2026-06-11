#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

priority_queue<P> pq;

ll a[225816],b[225816];

int main(void){
	int n,i;
	ll x,y,z,ans=0ll,tmp;
	P p;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	for(i=0; i<n; ++i){
		cin >> b[i];
		pq.push(P(b[i],i));
	}
	while(!pq.empty()){
		p = pq.top();
		pq.pop();
		i = p.second;
		x = b[(i+n-1)%n];
		z = b[(i+1)%n];
		tmp = (b[i]-a[i])/(x+z);
		ans += tmp;
		b[i] -= (x+z)*tmp;
		if(tmp && b[i]>a[i]){
			pq.push(P(b[i],i));
		}
	}
	for(i=0; i<n; ++i){
		if(a[i]-b[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
