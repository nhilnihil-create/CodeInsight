#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5, INF = 1e9;

int n, k, a[N];

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)  cin >> a[i];
    int l = 1, r = INF;
    while(l < r) {
        int mid = (l+r)/2,
            tot = 0;
        for(int i=0; i<n; i++) {
            int r = a[i] % mid;
            tot += a[i]/mid + (r>0) - 1;  
        }
        if(tot <= k) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << l;
}