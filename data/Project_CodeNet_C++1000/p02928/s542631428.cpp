#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    long long int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int ans = 0;
    for(int i=0; i<n; i++){
        long long int front = 0;
        long long int back = 0;
        for(int j=0; j<i; j++){
            if(a[j] > a[i]) front += 1;
        }
        for(int j=i; j<n; j++){
            if(a[j] > a[i]) back += 1;
        }
        ans += ((k * (k-1) / 2) % MOD) * (front + back) + front * k;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}