#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	vector<int> cost(n);
	vector<vector<int> > gr;
	gr.assign(n,vector<int>(m));
	ll ans = 1LL<<50;
	for(int i = 0; i < n; i++){
		scanf("%d",&cost[i]);
		for(int j = 0; j < m; j++)
			scanf("%d",&gr[i][j]);
	}
	for(int i = 0; i < 1<<n; i++){
		ll auxi = 0;
		vector<int> v(m,x);
		for(int j = 0; j < n; j++){
			if(i&1<<j){
				auxi += cost[j];
				for(int h = 0; h < m; h++)
					v[h] -= gr[j][h];
			}
		}
		auto x = max_element(v.begin(), v.end());
		if(*x <= 0)
			ans = min(ans,auxi);
	}
	if(ans != 1LL<<50)
		printf("%lld\n", ans);
	else
		printf("-1\n");
	return 0;
}