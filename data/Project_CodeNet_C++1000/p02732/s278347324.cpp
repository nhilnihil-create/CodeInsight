#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]-1]++;
    }

    ll sum=0;
    for(int i = 0; i < n; i++) {
        ll x=0;
        for(int j = 1; j < b[i]; j++) {
            x += j;
        }
        sum+=x;
    }

    for(int i = 0; i < n; i++) {
        ll ans=sum-b[a[i]-1]+1;
        cout << ans << endl;
    }

    return 0;
}