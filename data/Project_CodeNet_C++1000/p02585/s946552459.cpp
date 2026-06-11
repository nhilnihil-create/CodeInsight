#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> p(n),c(n);
	vector<bool> visited(n,false);
	REP(i,n){
		cin >> p[i];
		p[i]--;
	}
	REP(i,n) cin >> c[i];
	
	vector<vector<ll>> way;
	vector<ll> score,w;
	ll now = 0;
	ll s = 0;
	bool loop = true;
	while(loop){
		visited[now] = true;
		w.push_back(now);
		
		if(!visited[p[now]]){
			s += c[p[now]];
			now = p[now];
		}else{
			s += c[p[now]];
			way.push_back(w);
			w.clear();
			score.push_back(s);
			s = 0;
			REP(i,n){
				if(!visited[i]){
					now = i;
					break;
				}
				if(i==n-1) loop = false;
			}
		}
	}
	
	vector<ll> rscore((int)way.size());
	REP(i,way.size()){
		chmax(score[i], (ll)0);
		rscore[i] = score[i]*(k/way[i].size());
	}
	
	ll ans = -1*(ll)1e13;
	REP(i,way.size()){
		ll sz = way[i].size();
		ll t = k%sz;
		ll smax = -1*(ll)1e13;
		REP(j,sz){
			ll sum = 0;
			REP(l,sz){
				sum += c[way[i][(j+l)%sz]];
				if(l < t){
					chmax(smax, rscore[i]+sum);
				}else{
					chmax(smax, rscore[i]-score[i]+sum);
				}
			}
		}
		chmax(ans, smax);
		
	}
	
	cout << ans << endl;
	
	return 0;
}