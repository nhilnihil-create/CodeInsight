#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    rep(i,n){
        cin >> w[i];
        sum += w[i];
    }
    int ans = 1e6;
    int now = 0;
    rep(i,n-1){
        now += w[i];
        ans = min(ans, abs(sum-now*2));
    }
    cout << ans << endl;
}