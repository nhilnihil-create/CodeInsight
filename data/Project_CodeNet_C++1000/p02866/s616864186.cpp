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
#define MOD 998244353
#define cey ce("Yes")
#define cen ce("No")
#define ceY ce("YES")
#define ceN ce("NO")


ll inv(ll a, ll p) {

	ll res = 1;
	while (p > 0) {
		if ((p & 1) == 1) { res *= a; res %= MOD; }
		a = a * a % MOD;
		p >>= 1;
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	map<int, int> K;
	int maxi = 0;
	fx(N) {
		int a;
		cin >> a;
		K[a]++;
		if (x==0&&a!=0) {
			ce(0);
			return 0;
		}
		maxi = max(maxi, a);
	}
	if (K[0]!=1) {
		ce(0);
		return 0;
	}

	ll ans = 1;
	fyg(maxi+1,2) {
		ans *= inv(K[y-1],K[y]);
		ans %= MOD;
	}
	ce(ans)
    return 0;
}

