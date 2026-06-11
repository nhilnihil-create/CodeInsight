#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

struct edge{
	int u,v;
	ll cost;
};

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

int main(){
	ll V,E;
	cin >> V >> E;
	vector<edge> e;
	vector<int> c;
	rep(i,V){
		c.push_back(i);
	}
	rep(i,E){
		int s,t;
		ll w;
		cin >> s >> t >> w;
		edge e1 = {s,t,w};
		e.push_back(e1);
	}
	sort(e.begin(),e.end(),comp);
	
	ll ans = 0;
	
	rep(i,E){
		if(c[e[i].u] != c[e[i].v]){
			ans += e[i].cost;
			int temp = c[e[i].v];
			rep(j,V){
				if(c[j] == temp){
					c[j] = c[e[i].u];
				}
			}
		}
	}
	
	cout << ans << endl;
    return 0;
}


