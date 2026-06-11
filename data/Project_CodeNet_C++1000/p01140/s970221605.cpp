#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;

//-----------------------------------------------------------------------------

int H,W,h[1510],w[1510],ans;
int cnt_h[1500010],cnt_w[1500010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while(true) {
		ans=0;
		REP(i,1500010) cnt_h[i]=cnt_w[i]=0;
		cin>>H>>W;
		if(H==0&&W==0) break;
		REP(i,H) {
			cin>>h[i+1];
			h[i+1]+=h[i];
		}
		REP(i,W) {
			cin>>w[i+1];
			w[i+1]+=w[i];
		}
		FOR(i,1,H+1) {
			FOR(j,0,i) {
				cnt_h[h[i]-h[j]]++;
			}
		}
		FOR(i,1,W+1) {
			FOR(j,0,i) {
				cnt_w[w[i]-w[j]]++;
			}
		}
		REP(i,1500010) ans+=cnt_h[i]*cnt_w[i];
		cout<<ans<<endl;
	}

	return 0;
}

