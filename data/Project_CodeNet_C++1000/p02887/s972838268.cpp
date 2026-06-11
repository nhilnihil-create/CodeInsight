#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = n;
    rep(i,n-1) {
        if(s[i] == s[i+1])
            ans--;
    }
    
    cout << ans << endl;
    
    
    return 0;
}
