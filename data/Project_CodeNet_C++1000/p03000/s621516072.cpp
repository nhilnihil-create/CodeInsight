#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n);i++)
using namespace std;
using ll = long long;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> d(n);
    d[0] = 0;
    rep(i,n){
        int a;
        cin >> a;
        d[i+1] = d[i] + a;
    }
    int ans = 0;
    rep(i,n+1){
        if(d[i] <= x){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}