#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, x, a[N];
int main() {
    cin >> n >> x;
    for(int i=0; i<n; i++)  cin >> a[i];
    int cur = 0;
    for(int i=0; i<n; i++) {
        cur += a[i];
        if(cur > x) {
            cout << i+1;
            exit(0);
        }
    }
    cout << n+1;
}
