#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(ll i=st; i<ed; i++)
#define repn(i, st, ed) for(ll i=st; i<=ed; i++)
#define repb(i, ed, st) for(ll i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code

ll s[2010], t[2010];
ll ans[2010][2010];
int main()
{
	int n, m;
	cin>>n>>m;
	repn(i, 1, n) cin>>s[i];
	repn(i, 1, m) cin>>t[i];
	repn(i, 1, n)
	{
		repn(j, 1, m)
		{
			ans[i][j] = (ans[i-1][j] + ans[i][j-1]);
			if(s[i] != t[j]) ans[i][j] -= ans[i-1][j-1];
			if(s[i] == t[j]) ans[i][j]++;
			if(ans[i][j] < M) ans[i][j] += M;
			ans[i][j] %= M;
		}
	}
	cout<<ans[n][m]+1<<endl;
}
