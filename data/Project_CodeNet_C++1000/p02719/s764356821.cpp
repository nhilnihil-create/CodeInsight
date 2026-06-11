// C - Replacing Integer
#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll n, k;
    cin >> n >> k;
    ll t = n%k;
    ll ans = min(t, k-t);
    cout << ans << endl;
    return 0;
}