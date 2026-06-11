#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
    }
    
    vector<int> ans;
    ans.push_back(p[0]);
    for(int i = 1; i < n; i++) {
        if(p[i] <= ans.back())
            ans.push_back(p[i]);
    }
    
    cout << ans.size() << endl;
    
    
    return 0;
}
