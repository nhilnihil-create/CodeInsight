#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    int a[n];
    for(int i=0; i<n; ++i)
        cin >> a[i];
    int ans=a[n-1]-a[0];
    for(int i=1; i<n; ++i)
        ans=min(a[i-1]+k-a[i], ans);
    cout << ans;
}