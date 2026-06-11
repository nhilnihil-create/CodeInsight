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
	
	FOR(i,1,N) cin>>A[i];
	
	sort(A+1,A+N+1);
	
	ld cur = ld(A[1] + A[2]) / ld(2);
	
	FOR(i,3,N){
		cur = (cur + A[i]) / 2;
		
		
	}
	cout<<cur;
}
