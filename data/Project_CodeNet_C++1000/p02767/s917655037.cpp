// C - Rally
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int ans = 0;
    for(int i=1; i<101; i++){
        int a, b = 0;
        rep(j, n){
            a = x[j]-i;
            a = a*a;
            b += a;
        }
        if(i>=2) ans = min(ans, b);
        else ans = b;
    }
    cout << ans << endl;
    return 0;
}