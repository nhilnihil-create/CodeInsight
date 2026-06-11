#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define mod (ll)(1e9+7)
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
int a[200005];
vector<int>b(200005,0);
int cnt = 0;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=n;i>=1;i--)
	{
		int balls = 0;
		for(int j=i;j<=n;j+=i)balls+=b[j];
			
		if(balls%2 != a[i]%2){b[i] = 1;cnt++;}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)if(b[i])cout<<i<<" ";
}