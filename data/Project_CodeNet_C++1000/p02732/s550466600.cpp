#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += b[i]*(b[i]-1LL)/2LL;
    }    
    for (int i = 0; i < n; i++) {
        long long x = b[a[i]];
        long long y = x - 1;
        long long ans = sum - x*(x-1LL)/2LL + y*(y-1)/2LL;
        cout << ans << endl;
    }
}