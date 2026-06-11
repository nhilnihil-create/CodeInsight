#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;

int n,k;
int a[200001];
//二分探索テンプレ

// index が条件を満たすかどうか
bool isOK(int index, int k) {
    int res = 0;
    rep(i,n) {
        res += (a[i]+index-1)/index-1;
    }
    if (res <= k) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int k) {
    int ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = 1e9; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, k)) ok = mid;
        else ng = mid;
    }
    return ok;
}
 
int main() {

    cin >> n >> k;
    rep(i,n)    cin >> a[i];

    int ans = binary_search(k);
    cout<<ans<<endl;

 return 0;
}
