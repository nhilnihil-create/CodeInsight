#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    
    int sum = 0;
    rep(i,n) {
        sum += a[i];
    }
    
    int cnt = 0;
    sum = (sum + 4*m-1) / (4 * m);
    rep(i,n) {
        if(a[i] >= sum)
            cnt++;
    }
    
    if(cnt >= m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
