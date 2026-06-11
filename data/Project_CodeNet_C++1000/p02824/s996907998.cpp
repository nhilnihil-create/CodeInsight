#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 100000;

ll arr[MAX_N+1];
int N, M, V, P;
vector<ll> vt;
ll sum[MAX_N+1];
int ans = 0;

int main(){
	scanf("%d%d%d%d", &N, &M, &V, &P);
	for(int i=1; i<=N; i++){
		scanf("%lld", &arr[i]);
		vt.pb(arr[i]);
	}
	sort(vt.begin(), vt.end());
	vt.pb(INFLL);
	sum[0] = vt[0];
	for(int i=1; i<vt.size(); i++){
		sum[i] = vt[i] + sum[i-1];
	}
	for(int i=0; i<N; i++){
		ll n = vt[i] + (ll)M;
		ll S=(ll)M;
		int idx = N-P;
		if(vt[N-P]>n)	continue;
		if(idx>i)	S += (ll)(idx-i) * n - sum[idx] + sum[i];
		S += (ll)(P-1) * (ll)M;
		S += (ll)min(i, N-P) * (ll)M;
		if(S>=(ll)M*(ll)V){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
