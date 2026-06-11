#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main(){
    int  n;
    int ans = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n)rep(j, n)rep(k, n){
        if(i < j && j < k){
            if(a[i] == a[j]) continue;
            if(a[i] == a[k]) continue;
            if(a[k] == a[j]) continue;
            if((long long)a[i]+a[j]+a[k] <= max({a[i], a[j], a[k]}) * 2) continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}