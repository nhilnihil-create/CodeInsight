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
	int arr[n + 1];
	for(int i=1;i <= n; i++){
		cin >> arr[i];
	}
	int check[n + 1], ans = 0;
	fill(check, 0);
	for(int i=n; i>=1; i--){
		int sum = 0;
		for(int j=i; j<=n; j+=i){
			sum += check[j];
		}
		if(sum % 2 != arr[i] % 2){
			check[i] = 1;
			ans++;
		}
	}
	cout << ans << "\n";
	for(int i=1; i <=n ; i++){
		if(check[i]){
			cout << i << " ";
		}
	}
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