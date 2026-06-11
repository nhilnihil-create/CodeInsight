#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

// 最大公約数
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// 最小公倍数(overflowに注意した)
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll n, m;
vector<ll> a;

ll maeshori(){
    // かくa[i]は、2で割れる回数が等しいことが条件なので、予め割れるだけわる。
    // (これがoverflow対策になる。)
    for(int i=0; i<n; i++){
        a[i] /= 2;
    }
    while(a[0] % 2 == 0){
        for(int i=0; i<n; i++){
            if(a[i] % 2 != 0) return 0;
            a[i] /= 2;
        }
        // 同時にmも2で割っておく
        m /= 2;
    } 
    // a[0] で判定しているので、まだ2が生き残っているかもしれない。
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0) return 0;
    }
    ll ans;
    ll Xmin = 1;
    for(int i=0; i<n; i++){
        Xmin = lcm(Xmin, a[i]);
    }
    if(m - Xmin < 0) return 0;
    ans = (m / Xmin + 1) / 2;
    return ans;
}
int main(void){
    
    cin >> n >> m;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ll ans;
    ans = maeshori();
    cout << ans << endl;
    return 0;
}