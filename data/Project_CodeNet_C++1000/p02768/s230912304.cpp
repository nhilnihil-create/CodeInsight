#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (1000000000+7)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;


ll gcd(ll a, ll b) {
    if(b==0) return abs(a);
	else return gcd(b, a%b);
}

ll kaijo[200010];
void init() {
	kaijo[0] = 1;
	for (ll i = 1;i <= 200000;i++)kaijo[i] = (kaijo[i - 1] * i) % N;
}
 
ll inv(ll x,ll power) {
	ll res = 1;
	ll k = power;
	ll y = x;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N*y%N) % N;
		k /= 2;
	}
	return res;
}
 
ll Comb(ll n, ll k) {
	if (n < 0 || k < 0 || (n - k) < 0)return 0;
	ll b = kaijo[n];
	ll c = kaijo[n - k];
	ll d = kaijo[k];
	ll cd = (c*d) % N;
	return ((b%N)*(inv(cd,N-2)) % N) % N;
}

int main(void){
    init();
    ll n,a,b;
    cin>>n>>a>>b;
    ll now = inv(2LL,n);
    ll tmp1=1,tmp2=1;
    for(ll i=1;i<=a;i++)tmp1 = (tmp1*inv(i,N-2))%N;
    for(ll i=n;i>n-a;i--){
        tmp1 = (tmp1*i)%N;
    }
    for(ll i=1;i<=b;i++)tmp2 = (tmp2*inv(i,N-2))%N;
    for(ll i=n;i>n-b;i--){
        tmp2 = (tmp2*i)%N;
    }
    now = (now-tmp1+N)%N;
    now = (now-tmp2+N)%N;
    now = (now-1+N)%N;
    cout<<(now+N)%N<<endl;
    return 0;
}