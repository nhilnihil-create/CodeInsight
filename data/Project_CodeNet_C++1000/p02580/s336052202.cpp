#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using P = pair<int,int>;
set<P> ps;
int h, w, m, hh[300005], ww[300005], a, b, hmax, wmax, hms[300005], wms[300005], eh, ew;
int main(){
	scanf("%d%d%d", &h, &w, &m);
	rep(i,m){
		scanf("%d%d", &a, &b); a--; b--;
		hmax = max(hmax, ++hh[a]);
		wmax = max(wmax, ++ww[b]);
		ps.emplace(a,b);
	}
	rep(i,h) if(hh[i] == hmax) hms[eh++] = i;
	rep(i,w) if(ww[i] == wmax) wms[ew++] = i;
	rep(i,eh) rep(j,ew) if(!ps.count({hms[i],wms[j]})){
		return 0 * printf("%d\n", hmax+wmax);
	}
	printf("%d\n", hmax+wmax-1);
}