#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
typedef long double ld;
#define maxn 1001

int N, A[maxn];

int32_t main()
{
	cin>>N;
	
	ld sm = 0;
	FOR(i,1,N){
		cin>>A[i];
		sm += (ld)1 / (ld)A[i];
	}
	
	
	cout<<setprecision(8)<<ld(1) / sm;
}
