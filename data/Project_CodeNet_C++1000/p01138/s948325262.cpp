#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
	int n;
	
	while(cin >> n,n){
		
		vector<int> imos(25*60*60);
		REP(i,n){
			int h,m,s,tmp;
			scanf("%d:%d:%d",&h,&m,&s);
			tmp = h*(3600) + m*60 + s;
			imos[tmp]++;
			scanf("%d:%d:%d",&h,&m,&s);
			tmp = h*(3600) + m*60 + s;
			imos[tmp]--;
		}
		
		REP(i,imos.size()-1){
			imos[i+1] += imos[i];
		}
		int ans = 0;
		REP(i,imos.size()){
			ans = max(ans,imos[i]);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
