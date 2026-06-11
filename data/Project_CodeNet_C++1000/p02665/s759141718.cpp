#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
    ll n; cin >> n;
    vector<ll> a(n + 1);
    rep(i, n + 1) cin >> a[i];

    if(n == 0){
        if(a[0] != 1){
            cout << -1 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }else if(a[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    vector<ll> a_sum(n + 2);
    a_sum[0] = 0;
    _rep(i, 1, n + 2){
        a_sum[i] = a_sum[i - 1] + a[i - 1];
    }
    ll ans = 1;
    ll b = 1;
    _rep(i, 1, n + 1){
        b = min(a_sum[n + 1] - a_sum[i], (b - a[i - 1]) * 2);
        ans += b;
        if(b < a[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}