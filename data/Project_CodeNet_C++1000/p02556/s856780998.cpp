#include<bits/stdc++.h>

#define SORT(v) sort(v.begin(),v.end())
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
#define sll(n,m) scanf("%lld %lld",&n,&m)
#define ss(cad) scanf("%s",cad)
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl; 
#define M 1000000007
#define N_MAX 100010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vp;

int main(){
	int n;
	si(n);
	vector<pair<ll, int> > v1(n), v2(n), vv1(n), vv2(n);
	for(int i = 0; i < n; i++){
		int a, b;
		sii(a, b);
		v1[i] = {(ll)2*1000000000 - a - b, i};
		v2[i] = {a + b, i};
		vv1[i] = {(ll)1000000000 - b + a, i};
		vv2[i] = {(ll)1000000000 - a + b, i};
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(vv1.begin(), vv1.end());
	sort(vv2.begin(), vv2.end());
	ll ans = 0;
	if(v1[0].scn != v2[0].scn)
		ans = (ll)2*1000000000 - v1[0].fst - v2[0].fst;
	else
		ans = max((ll)2*1000000000 - v1[0].fst - v2[1].fst, (ll)2*1000000000 - v1[1].fst - v2[0].fst);

	if(vv1[0].scn != vv2[0].scn)
		ans = max(ans, (ll)2*1000000000 - vv1[0].fst - vv2[0].fst);
	else
		ans = max(ans, max((ll)2*1000000000 - vv1[0].fst - vv2[1].fst, (ll)2*1000000000 - vv1[1].fst - vv2[0].fst));
	printf("%lld\n", ans);
	return 0;
}
