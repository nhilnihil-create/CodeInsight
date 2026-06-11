#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    rep(i,n) {
        cin >> h[i];
    }
    
    int ans, cnt;
    ans = cnt = 0;
    rep(i,n-1) {
        if(h[i] >= h[i+1]) {
            //cout << i << endl;
            cnt++;
        }
        else {
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    ans = max(ans,cnt);
    
    cout << ans << endl;
    
    
    return 0;
}
