#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll C, D;

ll warikirenai(ll x){
    ll c = x / C;
    ll d = x / D;
    ll e = __gcd(C, D);
    e = C*D / e;
    e = x / e;
    return x - c - d + e;
}

int main() {
    ll A, B; cin >> A >> B;
    cin >> C >> D;

    ll ans = warikirenai(B) - warikirenai(A-1);

    cout << ans << endl;
    

    return 0;
}