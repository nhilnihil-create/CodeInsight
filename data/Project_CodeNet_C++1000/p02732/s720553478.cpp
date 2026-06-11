#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef pair<int,int> P;

ll nC2(ll n){
    return n*(n-1)/2;
}

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    rep(i,n)a[i]--;

    vector<int> count(n);
    rep(i,n)count[a[i]]++;
    ll tmp = 0;
    rep(i,n){
        tmp += nC2(count[i]);
    }
    rep(i,n){
        ll ans = tmp;
        ans -= nC2(count[a[i]]);
        ans += nC2(count[a[i]]-1);
        cout << ans << endl;
    }

    return 0;
}