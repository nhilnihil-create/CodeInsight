#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL INF=1e12;

int main(){
	int N, D, A;
	cin >> N >> D >> A;
	vector<P> xh(N);
	rep(i,N){
		LL x, h;
		cin >> x >> h;
		xh[i]=P(x,(h+A-1)/A);
	}
	sort(xh.begin(),xh.end());
	vector<int> reach(N+1), damage(N+1);
	rep(i,N){
		P p=make_pair(xh[i].first+2*D,INF);
		int r=upper_bound(xh.begin(),xh.end(),p)-xh.begin();
		reach[i]=r;
	}
	LL ans=0;
	rep(i,N){
		if(i!=0) damage[i]+=damage[i-1];
		if(xh[i].second<=damage[i]) continue;
		LL num=xh[i].second-damage[i];
		ans+=num;
		damage[i]+=num, damage[reach[i]]-=num;
	}
	cout << ans << endl;

	return 0;
}