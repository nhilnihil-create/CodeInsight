#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin >> n;
    ll ans = LONG_MAX;

    for(ll i=1; i*i <= n; ++i){
        if(n%i==0){
            if(i != n/i)
                ans = min(ans, (i)+(n/i));
            else
                ans = min(ans, i+i);
        }
    }
    cout << ans-2;
    return 0;
}
