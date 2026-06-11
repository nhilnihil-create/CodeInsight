#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_N 200000

int main() {
    int n;
    vector<int> a(MAX_N+10);
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.begin() + n, greater<int>());

    long long ans = a[0];
    for (int i = 2; i < n; i++) {
        if (i % 2 == 0) ans += a[i/2];
        else ans += a[(i-1)/2];
    }
    
    cout << ans << endl;

}