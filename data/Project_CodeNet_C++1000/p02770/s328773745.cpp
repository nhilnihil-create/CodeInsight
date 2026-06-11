#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    ll k, q;
    cin >> k >> q;
    ll dd[k], d[k], n, x, m;
    REP(i, k) cin >> dd[i];

    REP(i, q){
        cin >> n >> x >> m;
        x %= m;
        ll s = 0;
        ll c = 0;
        REP(i, k) {
            d[i] = dd[i] % m;
            s += d[i];
            if(d[i] == 0) c++;
        }
        s *= (n-1)/k;
        c *= (n-1)/k;
        REP(i, (n-1)%k) {
            s += d[i];
            if(d[i] == 0) c++;
        }
        ll a = (x+s)/m + c;
        a = (n - 1) - a;
        cout << a << endl;
    }
} 