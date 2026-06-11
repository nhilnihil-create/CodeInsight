#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<vector<int>> mat;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	ll n,range,damage,x,h;

	//cordenada y cant de bombas necesarias para h=0
	vector<pair<int,int>> monster;
	cin>>n>>range>>damage;

	for(int i=0;i<n;i++)
	{
		cin>>x>>h;
		h=(h+damage-1)/	damage ;
		monster.emplace_back(x,h);
	}
	sort(monster.begin(),monster.end());

	ll ans=0;
	ll currentDamage=0;
	vector<ll> changes(n+1);
	for(int i=0;i<n;i++)
	{
		currentDamage+=changes[i];
		ll monsterh=monster[i].second - currentDamage;
		if(monsterh<=0)continue;
		//Encontrar el ult monst afectado
		int l=i;
		int r=n;
		while(l+1<r)
		{
			int m=(l+r)>>1;
			if(monster[m].first<=monster[i].first+2LL*range)
				l=m;
			else r=m;
		}
		changes[l+1]-=monsterh;
		currentDamage+=monsterh;
		ans+=monsterh;
	}

	cout<<ans<<endl;


	return 0;
}