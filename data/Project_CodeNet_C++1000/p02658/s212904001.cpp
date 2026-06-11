#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, A;
    long long multi = 1;
    long long ans = 0;
    cin >> N;
    vector<long long> vec;
    vector<long long> logvec;
    
    for (auto i = 0; i < N; i++) {
        cin >> A;
        vec.push_back(A);
        logvec.push_back(log10(A));
    }
    
    sort(vec.begin(), vec.end());
    sort(logvec.begin(), logvec.end());
    
    if (vec[0] == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // for (auto i : vec) {
    //     multi *= i;
    //     if (multi > powl(10, 18)) {
    //         cout << -1 << endl;
    //         return 0;
    //     }
    // }
    
    for (auto i = 0; i < N; i++) {
        multi *= vec[i];
        ans += logvec[i];
        
        if (multi > 1000000000000000000) {
            cout << -1 << endl;
            return 0;
        }
        
        
        
        if (ans >= 18) {
            if (multi == 1000000000000000000) {
                continue;
            }
            cout << -1 << endl;
            return 0;
        }
        
        
    }
    
    cout << multi << endl;
}
