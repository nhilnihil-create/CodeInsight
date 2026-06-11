#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fw(p) for(int w=0;w<(p);w++)
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define fyg(p,g) for(int y=(g);y<(p);y++)
#define fzg(p,g) for(int z=(g);z<(p);z++)
#define ce(d) cout<<d<<endl;
#define vecp(p) int aa;cin>>aa;(p).push_back(aa);
#define vecpl(p) long long aa;cin>>aa;(p).push_back(aa);
#define vecps(p) string aa;cin>>aa;(p).push_back(aa);
#define vecp2(p) cin>>aa;(p).push_back(aa);
#define vecpl2(p) long long a	b;cin>>ab;(p).push_back(ab);
#define vecps2(p) string ab;cin>>ab;(p).push_back(ab);
#define sorts(c) sort((c).begin(),(c).end());
#define reverses(c) reverse((c).begin(),(c).end());
#define vec(b) vector<int> (b);
#define vecl(b) vector<long long> (b);
#define vecs(b) vector<string> (b);
#define pb(b,a) (b).push_back((a));
#define doublece(a,b) cout<<(a)<<' '<<(b)<<endl;
#define pairs(s) vector<pair<int,int>> (s);
#define pairsp(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define MOD 1000000007
#define cey ce("Yes")
#define cen ce("No")
#define ceY ce("YES")
#define ceN ce("NO")

int main()
{

	int N, K;
	cin >> N >> K;

	vector<vector<int>> P(N+1);
	fx(N-1) {
		int a, b;
		cin >> a >> b;
		pb(P[a], b);
		pb(P[b], a);
	}

	ll ans = K;

	queue<pair<int,int>> G;
	bool flag[110000] = { false, };
	G.push(make_pair(1,0));
	while (!G.empty()) {
		auto g = G.front(); G.pop();
		flag[g.first] = true;
		if(g.second==0) {
			int s = P[g.first].size();
			if (s>=K) {
				ce(0);
				return 0;
			}
			fx(s) {
				ans *= (ll)K - 1 - x;
				ans %= MOD;
			}
			fx(s) {
				G.push(make_pair(P[g.first][x],1));
			}
		}
		else if (g.second==1) {
			int s = P[g.first].size() - 1;
			if (s >= K) {
				ce(0);
				return 0;
			}
			if (s<=0) {
				continue;
			}
			fx(s) {
				ans *= (ll)K - 2 - x;
				ans %= MOD;
			}
			fx(s+1) {
				if (flag[P[g.first][x]]) { continue; }
				G.push(make_pair(P[g.first][x], 1));
			}
		}
		
	}
	ce(ans)
    return 0;
}

