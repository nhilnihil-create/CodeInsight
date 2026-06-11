#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpl = vector<pll>;
using vvll = vector<vll>;

#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(ll i=0;i<((ll)n);i++)
#define REP1(i,n) for(ll i=1;i<((ll)n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


//abc173
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vpl edge(n);
    REP(i, n - 1) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v)
            swap(u, v);
        edge[i].FI=u;
        edge[i].SE=v;
    }

    //�����W��S�̘A����=���_��-�Ӑ�
    //���_
    ll vertex= 0;
    REP(i, n) {
		ll l = i + 1;
		ll r = n - i;
        vertex+= l * r;
    }


    //��
    ll e = 0;
    REP(i, n - 1) {
        ll u = edge[i].FI;
		ll v = edge[i].SE;
		ll l = u + 1;
		ll r = n - v;

		e += l * r;
	}

    ll ans = vertex - e;
    cout << ans << endl;
}


