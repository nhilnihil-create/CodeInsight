#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 5000+10;
const ll oo = numeric_limits<ll>::max();
int P[maxn],seen[maxn];
ll N,K,C[maxn];
vi graph[maxn];

int len(int u){
	seen[u] = 1;
	int res = 1;
	for(auto &v : graph[u]){
		if(seen[v])continue;
		res += len(v);
	}
	return res;
}
void dfs(int u,ll act,ll cnt,vector<ll> &vals){
	vals.pb(act);
	if(!cnt)return;
	for(auto &v : graph[u]){
		dfs(v,act+C[v],cnt-1,vals);
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	forn(i,0,N){
		cin >> P[i]; P[i]--;
		graph[i].pb(P[i]);
	}
	forn(i,0,N)cin >> C[i];
	ll res = -oo;
	forn(i,0,N){
		ll Ktmp = K;
		forn(j,0,N)seen[j] = 0;
		ll lenCiclo = len(i);
		ll cntPuedo = min(lenCiclo,Ktmp);
		
		//cout << i+1 << ":D\n";
		//cout << lenCiclo << ' ' << cntPuedo << '\n';
		
		vector<ll> vals;
		dfs(i,0,cntPuedo,vals);
		
		forn(j,1,(int)vals.size())res = max(res,vals[j]);
		//for(auto &x : vals)cout << x << ' ';
		//cout << '\n';
		
		Ktmp -= cntPuedo;
		if(Ktmp > 0 && vals.back() > 0){
			forn(j,0,(int)vals.size()){
				ll cicloCompleto = vals.back();
				ll Ktmptmp = Ktmp-j;
				if(Ktmptmp < 0)break;
				ll resTmp = vals[j];
				ll cntCompletos = Ktmptmp/lenCiclo;
				cicloCompleto += ll(cntCompletos)*cicloCompleto;
				resTmp += cicloCompleto;
				res = max(res,resTmp);
				//cout << i << ' ' << j << ' ' << cntCompletos << ' ' << resTmp << '\n';
			}
		}
	}
	cout << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
