#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    rep(i,n) {
        cin >> x[i];
    }
    
    int m = 1000010;
    for(int i = 1; i <= 100; i++) {
        int sum = 0;
        rep(j,n) {
            sum += abs(i-x[j]) * abs(i-x[j]);
        }
        m = min(sum,m);
    }
    
    cout << m << endl;
    
    
    return 0;
}


