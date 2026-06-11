#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n+1), cnt(n+1), c(n+1);
    ll sum = 0;
    for(int i=1; i<=n; ++i){
        int A;
        cin >> A;
        a[i] = A;
        cnt[A]++;
    }
    for(int i=1; i<=n; ++i){
        c[i] = cnt[i]*(cnt[i]-1)/2;
        sum += c[i];
    }
    for(int i=1; i<=n; ++i){
        ll ans = sum - (cnt[a[i]] - 1);
        cout << ans << endl;
    }
    return 0;
}