#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ll int
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 100001
#define int ll
string S,T;

int numS[maxn][26];
int N,M;

int _min(int i,int j){
	if (i == -1) return j;
	if (j == -1) return i;
	return min(i,j);
}
int32_t main(){
	fast;
	
	cin>>S>>T;
	
	int N = S.size(), M = T.size();
	
	mem(numS,-1);
	DEC(i,N-1,0){
		numS[i][(int)S[i] - 97] = _min(numS[i][(int)S[i] - 97], i);
		if (i < N-1) FOR(j,0,25) numS[i][j] = _min(numS[i][j], numS[i+1][j]);
	}
	
	int curstr = 0, curidx = 0;
	
	aFOR(i,T){
		if (numS[curidx][(int)i - 97] == -1){
			if (numS[0][(int)i - 97] == -1){
				cout<<-1;
				return 0;
			}
			curstr++;
			curidx = 0;
		}
		
		curidx = numS[curidx][(int)i - 97] + 1;
		if (curidx == S.size()){
			curidx = 0; curstr++;
		}
	}
	
	cout<<curstr * (ll)S.size() + curidx;
	
	
	
	
}

