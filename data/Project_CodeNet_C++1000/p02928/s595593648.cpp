#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    ll n , k;
    cin >> n >> k;
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                cnt1++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i] > a[j]){
                cnt2++;
            }
        }
    }
    ll m1 = k;
    ll m2 = (k * (k - 1) / 2) % 1000000007;
    cout << (cnt1 * m1 + cnt2 * m2) % 1000000007 << endl;
}
