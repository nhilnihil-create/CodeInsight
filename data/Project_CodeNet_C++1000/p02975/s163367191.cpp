#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // for(int i = 0; i < n - 2; i++){
    //     if(a[i] ^ a[i + 1] ^ a[i + 2]){
    //         cout << "No" << endl;
    //         return 0;
    //     }
    // }
    // if(a[n - 2] ^ a[n - 1] ^ a[0] || a[n - 1] ^ a[0] ^ a[1]){
    //     cout << "No" << endl;
    //     return 0;
    // }

    long long xo = 0;
    for(auto x : a){
        xo ^= x;
    }

    string ans = "Yes";
    if(xo){
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}