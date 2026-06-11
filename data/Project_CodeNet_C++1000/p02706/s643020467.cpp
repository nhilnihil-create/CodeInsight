#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    bool ans = true;
    rep(i,m){
        int a;
        cin >> a;
        n -= a;
        if(n < 0){
            ans = false;
            break;
        }
    }
    if(ans) cout << n << endl;
    else cout << -1 << endl;
    return 0;
}