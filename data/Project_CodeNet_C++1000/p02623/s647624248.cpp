#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll max(ll a, ll b){
    return (a>b)?a:b;
}

int main(){
    ll n, m, k;    cin >> n >> m >> k;
    vector<ll>a(n);
    rep(i, n)   cin >> a[i];
    vector<ll>b(m);
    rep(i, m)   cin >> b[i];
    vector<ll>sum_a(n+1);
    vector<ll>sum_b(m+1);
    sum_a[1] = a[0];
    for(int i = 2; i <= n; i++)  sum_a[i] += sum_a[i-1] + a[i-1];
    sum_b[1] = b[0];
    for(int i = 2; i <= m; i++)  sum_b[i] += sum_b[i-1] + b[i-1];
    ll ans = 0;
    rep(i, n+1){
        int ok = -1, ng = m+1;
        while(ok < ng-1){
            int ptr = (ok+ng)/2;
            if(sum_b[ptr] + sum_a[i] <= k){
                ok = ptr;
            }else{
                ng = ptr;
            }
        }
        if(ok < 0)  break;
        ans = max(ans, i+ok);
    }
    cout << ans << endl;
}
