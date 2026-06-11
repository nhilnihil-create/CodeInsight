#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end()  
#define sz(x) int(x.size()) 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=63;
const int mxn=2e5+5;
bool DEBUG=0;

int a[mxn],n,k;

bool works(int val){
	ll cnt=0;
	for(int i=0; i<n; i++){
		cnt+=(a[i]-1)/val;
	}
	//cerr<<val<<" --- "<<cnt<<"\n";
	return cnt<=k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    cin>>n>>k;
    for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int lo=1, hi=a[n-1],ans=1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		//cerr<<lo<<" "<<hi<<" "<<mid<<"\n";
		if(works(mid)){
			hi=mid-1;
		}else{
			lo=mid+1;
			ans=mid+1;
		}
	}
	cout<<ans<<"\n";
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
