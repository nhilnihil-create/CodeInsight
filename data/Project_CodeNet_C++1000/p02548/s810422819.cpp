
// Problem : C - A x B + C
// Contest : AtCoder - AtCoder Beginner Contest 179
// URL : https://atcoder.jp/contests/abc179/tasks/abc179_c
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
const ll N = 1e6;
vi findDivisors() 
{ 
  
    // Array to store the count 
    // of divisors 
    ll n = N;
    vi div(n + 1, 0); 
  
    // For every number from 1 to n 
    for (ll i = 1; i <= n; i++) { 
  
        // Increase divisors count for 
        // every number divisible by i 
        for (ll j = 1; j * i <= n; j++) 
            div[i * j]++; 
    } 
  
    // Print the divisors 
    return div;
} 
  
// Driver cod
int main() {
    SPEED;
    vi v = findDivisors();
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll c = 1; c < n; c++) {
    	ans += v[c];
    }
    cout<<ans;
    return 0;
}