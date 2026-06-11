#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n, a[N];
main() {
    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
    sort(a, a+n, greater<int>());
    int S = a[0];
    for(int i=1, j=2; i<n; i++) {
        if(j == n)  break;
        S += a[i]; 
        j++;
        if(j < n) {
            S += a[i];
            j++;
        }
    }
    cout << S;
}