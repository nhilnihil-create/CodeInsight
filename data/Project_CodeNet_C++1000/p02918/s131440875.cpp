#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int sum = n - 1;
    for(int i = 1; i < n; i++) if(s[i] != s[i - 1]) sum--;
    cout << min(n - 1, sum + 2 * k);
}