// C - Peaks
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    vector<bool> ok(n, true);
    vector<int> cnt(n, 0);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a -= 1, b -=1;
        if(h[a] < h[b]){
            ok[a] = false, ok[b] = true;
            cnt[a]++;
        }else if(h[a] > h[b]){
            ok[a] = true, ok[b] = false;
            cnt[b]++;
        }else{
            ok[a] = ok[b] = false;
            cnt[a]++; cnt[b]++;
        } 
    }
    int ans = 0;
    rep(i, n) if(ok[i] && cnt[i]==0) ans++;
    cout << ans << endl;
    return 0;
}