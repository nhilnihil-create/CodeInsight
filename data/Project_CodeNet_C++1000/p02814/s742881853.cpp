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

ll gcd(ll x, ll y) {

	if (x % y == 0) {
		return y;
	}
	else {
		return gcd(y, x % y);
	}

}

int main()
{
	int N, M;
	cin >> N >> M;
	ll lcm = 1;
	int cnt = 0;
	fx(N) {
		int m;
		cin >> m;
		lcm = m / 2 / gcd(lcm, m / 2) * lcm;
		if (lcm>M) {
			ce(0);
			return 0;
		}
		int i = 0;
		while (m%2==0) {
			i++;
			m /= 2;
		}
		if (x==0) {
			cnt = i;
		}
		else {
			if (cnt!=i) {
				ce(0);
				return 0;
			}
		}
	}

	ce((M/lcm+1)/2)


    return 0;
}

