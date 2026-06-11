#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    long int n;
    cin >> n;
    
    vector<pair<long int, int>> s;
    for(long int i = 2; i*i <= n; i++) {
        int cnt = 0;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        if(cnt != 0)
            s.emplace_back(i,cnt);
    }
    
    int ans = 0;
    if(n != 1)
        ans++;
    
    rep(i,s.size()) {
        int e = 1;
        while(s[i].second - e >= 0) {
            //cout << s[i].first << s[i].second << endl;
            s[i].second -= e;
            e++;
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
