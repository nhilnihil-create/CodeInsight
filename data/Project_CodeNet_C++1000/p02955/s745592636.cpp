#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    using Int = long long;
    
    Int n, k;
    cin >> n >> k;
    
    vector<Int> a(n);
    Int sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    auto f = [&](Int d) {
        vector<Int> r(n);
        Int sum_r = 0;
         
        for (int i = 0; i < n; i++) {
            r[i] = a[i] % d;
            sum_r += r[i];
        }
        
        sort(r.begin(), r.end());
        
        Int cnt = 0;
        
        for (int i = 0; i < n - sum_r / d; i++) {
            cnt += r[i];
        }
        
        return cnt <= k;
    };
    
    Int ans = 1;
    
    for (Int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            if (f(i)) {
                ans = max(ans, i);
            }
            
            if (sum % (sum / i) == 0 && f(sum / i)) {
                ans = max(ans, sum / i);
            }
        }
    }
    
    cout << ans << endl; 
}