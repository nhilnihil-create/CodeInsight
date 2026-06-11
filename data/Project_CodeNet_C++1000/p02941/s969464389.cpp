/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.06.22 22:24:54
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector< int > a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    queue< int > que;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            puts("-1");
            return 0;
        } else if (b[(i - 1 + n) % n] < b[i] && b[i] > b[(i + 1) % n]) {
            que.push(i);
        }
    }
    ll ans = 0;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        
        if (b[t] % (b[(t - 1 + n) % n] + b[(t + 1) % n]) == a[t] % (b[(t - 1 + n) % n] + b[(t + 1) % n])) {
            ans += (b[t] - a[t]) / (b[(t - 1 + n) % n] + b[(t + 1) % n]);
            b[t] = a[t];
            
            
        } else {
            ans += b[t] / (b[(t - 1 + n) % n] + b[(t + 1) % n]);
            b[t] %= (b[(t - 1 + n) % n] + b[(t + 1) % n]);
        }
        if (b[t] < a[t]) {
            puts("-1");
            return 0;
        }
        if (b[(t - 2 + n) % n] < b[(t - 1 + n) % n] && b[(t - 1 + n) % n] > b[t]) {
            que.push((t - 1 + n) % n);
        }
        if (b[t] < b[(t + 1) % n] && b[(t + 1) % n] > b[(t + 2) % n]) {
            que.push((t + 1) % n);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            puts("-1");
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}