#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<vector<int>> digit(60, vector<int>(2));
    for(int i=0; i<n; i++){
        for(int j=0; j<60; j++){
            digit[j][(a[i]>>j) & 1] += 1;
        }
    }

    long long int ans = 0, pow2 = 1;
    for(int i=0; i<60; i++){
        //cout << digit[i][0] << " " << digit[i][1] << endl;
        ans += ((pow2 * digit[i][0]) % MOD) * digit[i][1];
        ans %= MOD;

        pow2 *= 2;
        pow2 %= MOD;
    }
    cout << ans << endl;
    return 0;
}