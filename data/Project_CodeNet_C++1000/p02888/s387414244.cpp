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
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int ans = 0;
	sort(arr, arr + n);
	for(int i=0; i < n-2; i++){
		for(int j=i + 1; j<n-1; j++){
			int sum  = arr[i] + arr[j];
			int t = lower_bound(arr, arr + n, sum) - arr;
			if(t > j){
				ans += t - j - 1;
			}
		}
	}
	cout << ans ;
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