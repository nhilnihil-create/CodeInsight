#include <bits/stdc++.h>
using namespace std; 

int main() {
    int n; cin >> n; long long arr[n]; for (int i = 0; i < n; i ++) cin >> arr[i];
    sort(arr, arr + n); long long ans = 0; 
    for (int i = 0; i < n-1; i ++) {
        if (i == 0) {ans += arr[n-1]; continue;}
        if (i % 2 == 1) {ans += arr[n-(i/2+2)];}
        else {ans += arr[n-(i/2+1)];}
    } cout << ans << endl;
}