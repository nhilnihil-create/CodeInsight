#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
const ld pi = 3.14159265358979;
    
int run_test(){
	int n;
	cin >> n;
	ll arr[n];
	int p = 1; ll sum = 0;
	for(int i=0;i <n; i++){
		cin >> arr[i];
		if(p == 1){
			sum += arr[i];
		}
		else{
			sum -= arr[i];
		}
		p = !p;
	}
	vector<ll> ans;
	ans.pb(sum);
	for(int i=0; i<n-1; i++){
		ans.pb(arr[i]*2 - sum);
		sum = (arr[i] * 2) - sum;
	}
	for(auto x: ans){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}
    
int main(){
   FAST;
    ll t;
    t = 1;
     
    while(t--){
        run_test();
    }
}