#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<ll,ll>pll;
vector<pll>v;

int main()
{
	ll x;
	scanf("%lld",&x);
	for(int i=-500;i<=500;i++){
		ll cur = i;
		for(int j=2;j<=5;j++){
			cur *= i;
		}
		v.push_back(mp(i,cur));
	}
	for(int sz=v.size(),i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			if(v[i].second-v[j].second==x){
				printf("%lld %lld\n",v[i].first,v[j].first);
				return 0;
			}
		}
	}
}
