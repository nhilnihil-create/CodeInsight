#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    long long a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    long long ans = 0;
    long long digit = 1;
    for (int i=0; i<60; i++){
        long long one = 0, zero = 0;
        for (int j=0; j<n; j++){
            if((1LL << i) & a[j]) one++;
            else zero++;
        }
        long long add = (one * zero) % mod * digit % mod;
        ans = (ans + add) % mod;
        digit = (digit * 2) % mod;
    }
    cout << ans << endl;
}
