#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define ALL(a) a.begin(),a.end()
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}

signed main(){
	int N;
	cin >> N;
	vector<pair<int,int>>p(N);
	REP(i,N){
		cin>>p[i].first>>p[i].second;
	}
	vector<int>id(N);
	iota(ALL(id),0);
	sort(ALL(id),[&](int a,int b){return atan2(p[a].second,p[a].first)<atan2(p[b].second,p[b].first);});
	int ma = 0;
	REP(i,N){
		int x = 0,y = 0;
		REP(j,N){
			int nj = (i+j)%N;
			x+=p[id[nj]].first;
			y+=p[id[nj]].second;
			CHMAX(ma,x*x+y*y);
		}
	}
	printf("%.20lf\n",sqrt(ma));
}