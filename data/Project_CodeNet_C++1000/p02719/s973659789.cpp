#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int)(1e9 + 5)
#define MOD (int)(1e9) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k; cin >> n >> k;
    ll mod = n % k;
    cout << min(mod, k-mod) << '\n';
    return 0;
}