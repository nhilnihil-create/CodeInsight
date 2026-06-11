#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f(i,n) for(int i=0; i<n; ++i)
#define fi(i,st,n) for(int i=st; i<=n; ++i)
#define veci vector<int>
#define vecp vector<pair<int,int> >
#define vecl vector<ll>
int prime[100000+10];

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}

ll power(ll a, ll n, ll mod) {
	ll res = 1;
	while(n > 0) {
		if(n&1) {
			res = (res*a)%mod;
		}
		a = (a*a)%mod;
		n = n/2;
	}
	return res;
}

ll sum(int arr[], int n) {
	ll res = 0;
	f(i,n) {
		res += arr[i];
	}
	return res;
}

void seive() {
	prime[1] = 0;
	for(int i=2; i<=100000; i++) {
		prime[i] = 1;
	}
	for(ll i=2; i<=100000; i++) {
		if(prime[i]) {
			for(ll j=i*i; j<=100000; j+=i) {
				prime[j] = 0;
			}
		}
	}
}

ll ans = 0;

void solve(ll p[], ll c[], int k, int i, int visited[]) {
	visited[i] = 1;
	vector<ll> arr;
	arr.pb(c[i]);
	while(true) {
		int idx = p[i];
		if(visited[idx]) break;
		arr.pb(c[idx]);
		visited[idx] = 1;
		i = idx;
	}
	ll n = arr.size();
//	f(i,n) cout<<arr[i]<<" ";
//	cout<<n<<" ";
	ll sum[n+1] = {0};
	sum[0] = 0;
	for(int j=1; j<=n; j++) {
		ll res = 0;
		for (int i=0; i<j; i++) res += arr[i];
       	ll curr = res;
       	for(int i=j; i<n+j; i++) {
       		curr += arr[i%n] - arr[(i-j)%n];
       		res = max(res,curr);
		}
		sum[j] = res;
	}
//	cout<<sum[4]<<" ";
	if(k < n) {
		ans = max(ans,*max_element(sum+1,sum+k+1));
	}
	else {
		ans = max(ans,*max_element(sum+1,sum+n+1));
		if(k%n == 0) {
			ans = max(ans,(*max_element(sum+1,sum+n+1)) + sum[n]*(k/n-1));
		}
		else
			ans = max(ans,sum[n]*(k/n) + *max_element(sum+1,sum+k%n+1));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
//	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		int visited[n+1] = {0};
		ll p[n+1], c[n+1];
		for(int i=1; i<=n; i++) cin>>p[i];
		for(int i=1; i<=n; i++) cin>>c[i];
		ll maxi = *max_element(c+1,c+n+1);
		if(maxi <= 0) {
			cout<<maxi<<"\n";
		}
		else {
			for(int i=1; i<=n; i++) {
				if(!visited[i]) {
					solve(p,c,k,i,visited);
				}
			}
			cout<<ans<<"\n";
		}
		
 	}
 	return 0;
}
