#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll mod = (1000000007LL);
inline ll Mod(ll a, ll b){return (a%b);}
inline ll poww(ll a, ll b){ll res = 1;while (b > 0){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
void read(vector<int> &w, int n){w.resize(n);for(int i = 0; i < n; i++) cin>>w[i];}
void print(vector<int> &w){for(int i =0; i < sz(w); i++){if(i == sz(w) - 1) cout<<w[i]<<"\n";else cout<<w[i]<<" ";}}
int prodmod(vector<int> w);
int summod(vector<int> w);
///CUIDADO COM MAXN
#define N 300050

int n, m, q, k, v[N], ans;
pii w[N];
string s;
int p[N], c[N], vis[N];
vector<int> path[N];
int cor;
void dfs(int x){
	vis[x] = cor;
	path[cor].pb(x);
	if(!vis[p[x]]) dfs(p[x]);
}
int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>p[i];
	}
	for(int i = 1; i <= n; i++) cin>>c[i];
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		++cor;
		dfs(i);
	}
	for(int cc = 1; cc <= cor; cc++){
		vector<int> cop = path[cc];
		for(auto e: cop) path[cc].pb(e);
	}
	int anss =-(2e18);
	for(int cc = 1; cc <= cor; cc++){
		int sum = 0;
		for(auto w: path[cc])sum += c[w];
		sum /= 2;
		for(int resto = 0; resto < sz(path[cc])/2; resto ++){
			vector<int> pref;
			int opt = -(2e18);
			if(resto == 0) opt = 0;
			for(int i = 0; i < sz(path[cc]); i++){
				if(!pref.empty())pref.pb(pref.back() + c[path[cc][i]]);
				else pref.pb(c[path[cc][i]]);
				if(i >= resto - 1){
					int sum = pref[i] - (i-resto>=0?pref[(i - resto)]:0);
					opt=max(opt, sum);
				}
			}
			if(resto > k) continue;
			int resp;
			int loop = (k - resto)/(sz(path[cc])/2);
			if(resto == 0){
				if(loop >= 1) resp = max(sum, loop*sum) + opt;
              else resp = -(2e18);
			}
			else resp = max(0LL, loop*sum) + opt;
			// cout<<"resto "<<resto<<" "<<opt<<" "<<resp<<"\n";
			anss = max(anss, resp);
		}
	}
	cout<<anss<<"\n";
}
/*
    CUIDADO COM MAXN, MOD, OVERFLOW 
    >Colocar (>DEFINE INT LONG LONG<) no inicio do template
    >mod = (1e9 + 7), por padrao (NAO ESQUECER DE ALTERAR)
    >NAO ESQUECER DEFINE INT LONG LONG
    > N = 1 ? 
*/
int summod(vector<int> w){int curr=0;for(int i=0;i<sz(w); i++){curr = (curr+w[i])%mod;if(curr<0)curr+=mod;}return curr;}
int prodmod(vector<int> w){int curr = 1;
for(int i = 0; i < sz(w); i++){if(w[i] >= mod) w[i] %= mod;curr = (curr * w[i]) % mod;if(curr < 0) curr += mod;}return curr;}