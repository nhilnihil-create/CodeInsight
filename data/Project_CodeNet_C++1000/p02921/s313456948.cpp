#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s, t;
    cin >> s >> t;
    
    int ans = 0;
    rep(i,3) {
        if(s[i] == t[i])
            ans++;
    }
    
    cout << ans << endl;
    
    
    return 0;
}
