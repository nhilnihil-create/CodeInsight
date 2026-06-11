#include <bits/stdc++.h>
#include <complex>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef tuple<int,int,int> i3;
typedef std::pair<int, ii> iii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<ii> vii;
typedef std::vector<iii> viii;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll mod = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ld pi=acos(-1);
const double PI = acos(-1);
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);  // greater than or equal
#define ub(v,n) upper_bound(v.begin(), v.end(), n);  // greater than
#define all(x) (x).begin(), (x).end();
#define fi first;
#define se second;
#define endl '\n';
#define loop(i,n) for(int i=0;i<(n);i++);
#define FOR(i, m, n) for(int i = m; i < n; i++);

ll gcd(ll a, ll b) {return b==0 ? a : gcd(b,a%b);}
ll add(ll x, ll y) { return ((x + y) % MOD + MOD) % MOD;}
ll sub(ll x, ll y) { return ((x - y) % MOD + MOD) % MOD;}
ll mult(ll x, ll y) { return (x * y) % MOD;}
ll po(ll base, ll exp, ll mod){
	if(exp==0) return 1;
	if(exp&1) return (base*po(base,exp-1,mod))%mod;
	else return po((base*base)%mod, exp/2,mod);
}


int c[13];
int a[13][13];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n,m,x;
  cin >> n >> m >> x;
  for (int i=0; i<n; i++){
  	cin >> c[i];
  	for (int j=0; j<m; j++){
  		cin >> a[i][j];
  	}
  }
 ll cost=INF;
 for (int i=0; i<(1<<n); i++){
 	ll temp=0;
 	vector<int> counter(m+1,0);
 	for (int j=0; j<n; j++){
 		if (i&(1<<j)) {
 			temp+=c[j];
 			for (int k=0; k<m; k++) counter[k]+=a[j][k];
 		}
 	}
 	bool check=true;
 	for (int j=0; j<m; j++){
 		if (counter[j]<x) check=false;
 	}
 	if (check) cost=min(cost,temp);
 }

 if (cost!=INF) {cout<<cost<<endl;}
 else {cout<<-1<<endl;}

  
}


