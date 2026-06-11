#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n = 0;
    int is = 0;
    int aVal;
    ll ans = 0;
    // 人数入力
    cin >> n;
    // フレンドリーさ入力
    vector<int> a(n);
    rep(i, n) {
        cin >> aVal;
        a.push_back(aVal);
    }
    // 降べきの順にそろえる
    sort(a.begin(), a.end(), greater<>());
    // 要素数が偶数か奇数か確認
    // 偶数
    ans = ans + a[0];
    if (n % 2 == 0) {
        for (is = 1;is < n / 2;is++) {
            ans = ans + a[is] * 2;
        }
    }
    // 奇数
    else{
        for(is = 1;is < n / 2;is++) {
            ans = ans + a[is] * 2;
        }
        ans = ans + a[n / 2];
    }
    cout << ans << endl;
    return 0;
}