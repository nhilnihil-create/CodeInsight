#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int A[101010];
ll L[101010], R[1010101];
int main() {
    int n;
    cin >> n;
    rep(i,n+1) cin >> A[i];
    L[n] = R[n] = A[n];
    for(int i = n-1; i >= 0; --i){
        L[i] = A[i] + (L[i+1]+1)/2;
        R[i] = A[i] + R[i+1];
    }
    if(L[0]>1) {cout << -1 << endl; return 0;}
    ll now = 1;
    ll ans = 0;
    rep(i,n+1) {
        ans += now;
        now-=A[i];
        now = min(now*2, R[i+1]);
    }
    cout << ans << endl;
    return 0;
}