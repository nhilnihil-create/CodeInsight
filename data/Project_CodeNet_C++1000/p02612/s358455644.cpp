#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long int;
using P = pair<int, int>;

int main() {
    int n,ans;
    cin >> n;
    ans = 0;
    rep(i,11) {
        if (i*1000 >= n) {
            ans = i*1000 - n;
            break;
        }
    }    
    cout << ans << endl;
    return 0;
}

