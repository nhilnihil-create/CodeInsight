#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vll vector<ll>
#define vpll vector<pll>
#define eb emplace_back
#define MAX 999999999999999
int main(){
	ll n, ans = 0;
	cin >> n;
	for (int i = 2; i <= 2000000; i++){
		if (n % i == 0){
			ll c = 0, bruh;
			while (n % i == 0) n /= i, c++;
			for (int j = 1; j < 100; j++){
				if (c < (j * (j + 1) / 2)){
					bruh = j;
					break;
				}
			}
			ans += bruh - 1;
		}
	}
	if (n != 1) ans++;
	printf("%lld\n", ans);
}