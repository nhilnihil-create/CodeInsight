#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;


int main() {
    ll N;
    cin >> N;
    vector<ll> ans(N, 0);
    rep(i,N - 1){
        ll tmp;
        cin >> tmp;
        tmp--;
        ans[tmp]++;
    }
    
    rep(i,N){
        cout << ans[i] << endl;
    }
}