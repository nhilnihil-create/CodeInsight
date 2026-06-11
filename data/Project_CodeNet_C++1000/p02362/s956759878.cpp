#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main()
{
	int V,E,R;
	cin >> V >> E >> R;
	vector<vector<pair<int,int>>> G(V);
	vector<ll> D(V,INF);
	for(int i = 0;i<E;i++)
	{
		int s,t,d;
		cin >> s >> t >> d;
		G[s].emplace_back(t,d);
	}

	D[R] = 0;
	for(int i = 0;i<V;i++)
	{
		bool update = false;
		for(int j = 0;j<V;j++)
		{
			//if(update == false)break;
			for(auto k:G[j])
			{
				if(D[k.first]>D[j]+k.second&&D[j]!=INF)
				{
					update = true;
					D[k.first] = D[j] + k.second;
				}
			}
		}
		if(update==false)break;
		if(i==V-3)
		{
			cout<<"NEGATIVE CYCLE"<<endl;
			return 0;
		}
	}
	for(auto i:D)
	{
		if(i==INF)
		{
			cout<<"INF"<<endl;
		}
		else
		{
			cout<<i<<endl;
		}
		
	}
}
