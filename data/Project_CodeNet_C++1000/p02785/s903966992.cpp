#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> h(n);
    rep(i,n) {
        cin >> h[i];
    }
    
    sort(h.rbegin(), h.rend());
    
    long int sum = 0;
    for(int i = k; i < n; i++) {
        sum += h[i];
    }
    
    cout << sum << endl;
    
    
    return 0;
}


