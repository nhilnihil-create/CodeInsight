
// Problem : C - Ubiquity
// Contest : AtCoder - AtCoder Beginner Contest 178
// URL : https://atcoder.jp/contests/abc178/tasks/abc178_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'
#define vi vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define fi first
#define se second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()

const ll inf=0x3f3f3f3f3f3f3f3f;
ll power(ll a, ll b, ll p) {
 	ll rtn = 1;
 	while(b) {
 		if(b & 1) {
 			rtn = (rtn % p * a % p) % p;
 		}
 		a = (a % p * a % p) % p;
 		b /= 2;
 	}
 	return rtn % p;
 }

int main() {
    SPEED;
    ll n;
    cin>>n;
    ll p = 1e9 + 7;
    if(n < 2) {
    	cout<<0;
    	return 0;
    }
    ll ans = 0;
    ans = ((power(10, n, p) + power(8, n, p)) % p - (2 * power(9, n, p)) % p + p) % p;
    cout<<ans;
    return 0;
}