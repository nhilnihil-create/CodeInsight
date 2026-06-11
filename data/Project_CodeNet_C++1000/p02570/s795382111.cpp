#include <bits/stdc++.h>
#define load ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
#define ll long long
#define ull unsigned long long
#define fori(i,n) for (int i=0; i<int(n);i++)
#define srt(v) sort(v.begin(), v.end())
#define MOD 1000000007
const int INF = 1e9;
const double PI = 3.14159265358979323846;
ll gcd(ll a, ll b) {
    return b != 0 ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}
ll spow(ll base, ll exp){
	ll ans = 1;
	for(ll i=0;i<exp;i++) ans = ans * base % MOD;
	return ans;
}
ll divide(ll a, ll b){
	return a * spow(b, MOD-2) % MOD;
}
void solve(){
	
}

int main(){
	//~ load;
	//~ int t;
	//~ cin >> t;
	//~ while(t--){
		//~ solve();
	//~ }
	
	int d, t, s;
	cin >> d >> t >> s;
	if (t*s >= d){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
	
}

