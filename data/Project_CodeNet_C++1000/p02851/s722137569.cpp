#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define fill(a,val)  memset(a,val, sizeof (a))
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(cont) cont.begin(), cont.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(max(a,d),max(b,c))
#define MAX   1e9
#define MIN  -1e9
#define PI 3.14159265358979
#define eps 1e-9
typedef map<int,int> mpi;
typedef set<int> seti;
typedef multiset<int> mseti;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i, n)    for(long long int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(long long int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(long long int i = a; i >= (n); --i)
#define repn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define trav(a, x) for(auto& a : x)
#define dbg(x) cout << #x << " = " << x << '\n'
#define dbg2(x,y) cout<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl
#define inp(a,start,len) for(long long int i = start;i < len;i++) cin>>a[i]
struct Interval{ll start,end;};
bool compare(Interval i1, Interval i2) {return (i1.start < i2.start);}

ll dp[200005][2];// 0 for me and 1 for friend
ll mod = 998244353;

ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int main(){
	fio;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll T = 1;
	// cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		ll a[n+1];
		repA(i,1,n)
		cin>>a[i];
		ll sum[n+1];
		sum[0] = 0;
		repA(i,1,n)
		sum[i] = sum[i-1] + a[i];
		ll arr[n+1];
		arr[0] = 0;
		rep(i,n+1)
		arr[i] = (sum[i] - i)%k;
		map<ll,ll> count;
		count[0]++;
		ll ans = 0;
		// cout<<ans
		repA(i,1,n){
			if(i<=k-1){
				ans+=count[arr[i]];
				count[arr[i]]++;
			}
			else{
				count[arr[i-k]]--;
				ans+=count[arr[i]];
				count[arr[i]]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
