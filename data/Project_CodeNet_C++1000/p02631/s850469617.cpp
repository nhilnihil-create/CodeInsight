#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum ^= a[i];
    }
    rep(i, 0, n) {
        cout << (sum ^ a[i]) << endl;
    }
    return 0;
}