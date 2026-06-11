#include<bits/stdc++.h>
const int mod=1e9+7;
typedef long long ll;
const int N=2e5+5;
int main()
{
	// std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	// freopen("a.in","r",stdin);
	// int T;scanf("%d",&T);while(T--){
	ll n,p;std::cin>>n>>p;
	std::string s;std::cin>>s;
	if(p==2||p==5)
	{
		ll ans=0;
		for(int i=0;i<n;i++) if((s[i]-'0')%p==0) ans+=i+1;
		printf("%lld\n",ans);
		return 0;
	}
	ll ans = 0;
	std::map<ll,ll>mp;
	ll cnt = 0;
	mp[0] = 1;
	ll bas = 1;
	for(int i = s.size() - 1; i >= 0; i--){
		ans = (ans + (s[i] - '0') * bas)%p;
		cnt += mp[ans]++;
		bas = bas * 10 % p;
	}
	std::cout<<cnt<<'\n';
	// }
	return 0;
}