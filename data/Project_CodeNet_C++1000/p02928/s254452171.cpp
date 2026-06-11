#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e+9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll cnt = 0;
    vector<ll> smaller(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                cnt++;
                smaller[i]++;
            } else if(a[i] < a[j]){
                smaller[j]++;
            }
        }
    }
    cnt = cnt * k % MOD;
    for(int i = 0; i < n; i++){
        ll temp = (k * (k-1) / 2) % MOD;
        temp = temp * smaller[i] % MOD;
        cnt = cnt + temp % MOD;
    }
    cout << cnt % MOD << endl;
    return 0;
}