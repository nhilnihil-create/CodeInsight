#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
int gcd(int A,int B) {if(!B)return A;return gcd(B,A%B);}

int main()
{
	ll n,k,c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	vector<int>a,l;
	for(int i=0;i<n;i++)if(s[i] == 'o'){a.pb(i+1);i+=c;} //earliest xth workday
	for(int i=n-1;i>=0;i--)if(s[i] == 'o'){l.pb(i+1);i-=c;} //latest xth workday
	vector<int>ans;
	for(int i=0;i<k;i++){
		if(a[i] == l[k-i-1])cout<<a[i]<<endl;
	}
}