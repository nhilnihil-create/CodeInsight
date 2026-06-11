#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int d(ll n) {
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    ll n;
    cin >> n;
    ll a[210000];
    ll cnt[210000];
    rep(i, n) {
        ll A;
        cin >> A;
        A--;
        a[i] = A;
        cnt[A]++;
    }
    // rep(i, n) cout << cnt[i] << ' '; // 確認済
    // cout << endl;
    ll sum = 0;
    rep(i, n) {
        sum += cnt[i] * (cnt[i] - 1) / 2;
    }
    // cout << sum << endl;
    // int count;
    ll k;
    rep(i, n) {
        k = sum;
        k -= cnt[a[i]] * (cnt[a[i]] - 1) / 2;
        cnt[a[i]]--;
        // count = 0;
        // rep(j, n) {
            // count += cnt[j] * (cnt[j] - 1) / 2;
        // }
        // cout << count << endl;
        k += cnt[a[i]] * (cnt[a[i]] - 1) / 2;
        cout << k << endl;
        cnt[a[i]]++;
    }
    
}