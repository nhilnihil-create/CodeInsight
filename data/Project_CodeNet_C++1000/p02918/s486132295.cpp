#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int ans = 0;
    rep(i,n-1) {
        if(s[i] == s[i+1]) {
            ans++;
        }
    }
    
    ans = min(ans+2*k, n-1);
    
    cout << ans << endl;
    
    
    return 0;
}


