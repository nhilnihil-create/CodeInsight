#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i, N) cin >> h[i];
    sort(h.begin(), h.end(), greater<int>());
    ll ans = 0;
    rep(i, N){
        if(i <= K-1) continue;
        ans += h[i];
    }
    cout << ans << endl;
    return 0;
}