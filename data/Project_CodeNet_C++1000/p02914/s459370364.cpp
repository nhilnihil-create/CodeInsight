#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using ll = long long;
using namespace std;

ll n, a[100100], all, ans, save;

int main(){
    cin >> n;
    rep(i,n) cin >> a[i], all ^= a[i];
    rep(i,n) a[i] &= ~all;
    ll rank = 0;
    rrep(i,60){
        for (save = rank; save < n; save++) if (a[save] & (1ll<<i)) break;
        if (save == n) continue;
        if (save > rank) a[rank] ^= a[save];
        rep(j,n) if (j != rank) if (a[j] & (1ll<<i)) a[j] ^= a[rank];
        rank++;
    }
    rep(i,n) ans ^= a[i];
    cout << ans * 2 + all << endl;
}