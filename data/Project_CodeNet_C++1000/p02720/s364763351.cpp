// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;

        int k = 0;
        vector<int> v;
        for(int i = 1; i <= 9; i++)
            v.push_back(i);
        while(v.size() < n) {
            int x = v[k], y = x % 10;
            if(y == 0) {
                v.push_back(10 * x);
                v.push_back(10 * x + 1);
            }
            else if(y == 9) {
                v.push_back(10 * x + 8);
                v.push_back(10 * x + 9);
            }
            else {
                v.push_back(10 * x + y - 1);
                v.push_back(10 * x + y);
                v.push_back(10 * x + y + 1);
            }
            k++;
        }

        cout << v[n - 1] << '\n';
        
    }
    
    return 0;
}

