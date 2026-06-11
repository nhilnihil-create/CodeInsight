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
    
    map<string,ll> m;
    rep(i,n) {
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        
        m[s]++;
    }
    
    ll ans = 0;
    for(auto x : m) {
        if(x.second > 1)
            ans += x.second * (x.second - 1) / 2;
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}


