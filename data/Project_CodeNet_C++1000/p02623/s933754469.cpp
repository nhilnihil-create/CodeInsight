#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> a(N), b(M);
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];
    vector<ll> suma(N+1, 0), sumb(M+1, 0);
    for(int i = 1; i < N+1; i++) suma[i] = suma[i-1] + a[i-1];
    for(int i = 1; i < M+1; i++) sumb[i] = sumb[i-1] + b[i-1];
    int ans = 0;
    //a基準
    for(int i = 0; i < N+1; i++){
        int mx = 0;
        if(suma[i] <= K) mx = i;
        else break;
        int key = K - suma[i];
        mx += (upper_bound(sumb.begin(), sumb.end(), key) - sumb.begin() - 1);
        ans = max(ans, mx); 
    } 
    //b基準
    for(int i = 0; i < M+1; i++){
        int mx = 0;
        if(sumb[i] <= K) mx = i;
        else break;
        int key = K - sumb[i];
        mx += (upper_bound(suma.begin(), suma.end(), key) - suma.begin() - 1);
        ans = max(ans, mx);
    }
    cout << ans << endl;
    return 0;
}