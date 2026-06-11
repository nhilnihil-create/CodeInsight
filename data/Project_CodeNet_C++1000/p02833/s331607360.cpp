#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

ll n;

void solve(){
    cin >> n;
    if(n%2 == 1){
        cout << "0\n";
    }
    else{
        ll ans = 0;
        for(ll i = 10; i <= n; i *= 5){
            ans += n/i;
        }
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}