// Created by AboAbdoMC
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int OO = 1e9+7;
const int MOD = 1e9+7;
const int N = 1e2+7;

double x[N],y[N];
int n;

double f()
{
	vector<pair<double,double> > vec;
	vec.pb({0,0});
	rep(i,n)
	{
		vector<pair<double,double> > vec2;
		for(auto p:vec)
		{
			vec2.pb(p);
			vec2.pb({p.f+x[i],p.s+y[i]});
		}

		sort(vec2.begin(), vec2.end());
		reverse(vec2.begin(), vec2.end());
		vec.clear();
		for(auto p:vec2)
		{
			if (vec.size() == 0||p.f > vec[vec.size()-1].f || p.s > vec[vec.size()-1].s) vec.pb(p);
		}
	}

	double ret = 0;
	for(auto p:vec) ret = max(ret,sqrt(p.f*p.f+p.s*p.s));

	return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    rep(i,n) cin >> x[i] >> y[i];
    double ans = f();
    rep(i,n) x[i] *= -1;
    ans = max(ans,f());
    rep(i,n) y[i] *= -1;
    ans = max(ans,f());
    rep(i,n) x[i] *= -1;
    ans = max(ans,f());

    cout << fixed << setprecision(10);
    cout << ans << '\n';
    return 0;
}