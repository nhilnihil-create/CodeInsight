#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n;
    long int k;
    cin >> n >> k;
    
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<int> all(200005), r;
    
    int ans = 0;
    int p = 1;
    int cnt = 0;
    while(all[p] <= 2) {
        if(all[p] <= 1)
            cnt++;
        
        if(k == cnt - 1) {
            ans = p;
            break;
        }
        
        all[p]++;
        if(all[p] == 2) {
            r.push_back(p);
        }
        p = a[p];
    }
    
    if(k > cnt) {
        k -= cnt;
        ans = r[k % (int)r.size()];
    }
    
    cout << ans << endl;
    
    return 0;
}


