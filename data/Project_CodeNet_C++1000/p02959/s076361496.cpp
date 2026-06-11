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
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n);
    for(int i=0; i<=n; ++i)
        cin >> a[i];

    for(int i=0; i<n; ++i)
        cin >> b[i];
    

    ll ans = 0;
    for(int i=0; i<n; ++i){
        ans += min(b[i], a[i]);
        b[i] -= min(b[i], a[i]);

        ans += min(b[i], a[i+1]);
        a[i+1] -= min(b[i], a[i+1]);
    }

    cout << ans;
}
