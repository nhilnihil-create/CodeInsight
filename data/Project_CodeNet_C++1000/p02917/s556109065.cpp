// C - Maximal Value
#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i, n-1) cin >> b[i];
    int ans = b[0];
    for(int i=0; i<n-2; i++){
        ans += (min(b[i], b[i+1]));
    }
    ans += b[n-2];
    cout << ans << endl;
    return 0;
}