#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e5 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	int n,k;
	cin >> n >> k;
	int a[1100];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int ans = 0;
    for(int i=0; i<k; i++){ 
    	ans+=a[i];
    }
    cout << ans << "\n";
    return 0;
}	