#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, allxor = 0;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll> > ls(62);
    for(int i=0;i<n;i++){
        cin >> a[i];
        allxor ^= a[i];
    }
    // bitの立っているa[i]の個数が奇数であるようなbitをおろす
    // そのようなbitは全体のxorでbitが立っている
    for(int i=0;i<n;i++){
        a[i] &= ~allxor;
    }
    // 掃き出し法
    // 独立なbitは自由にそのbitを上げ下げできる
    int rank = 0;
    for(int i=60;i>=0;i--){
        int k = -1;
        for(int j=rank;j<n;j++){
            if((a[j]>>i)&1){
                k = j;
                break;
            }
        }
        if(k == -1) continue;
        if(k != rank) a[rank] ^= a[k];
        for(int j=0;j<n;j++){
            if(j == rank) continue;
            a[j] = min(a[j], a[j]^a[rank]);
        }
        rank++;
    }
    ll ans = 0;
    // 上から立てられるbitを立てる
    for(int i=0;i<n;i++){
        ans = max(ans, ans^a[i]);
    }
    ans *= 2;
    ans += allxor;
    cout << ans << endl;
    return 0;
}
