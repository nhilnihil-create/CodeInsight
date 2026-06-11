#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n), x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        x[i] = i + a[i];
        y[i] = i - a[i];
    }
    sort(y.begin(), y.end());

    long long int ans = 0;
    for(int i=0; i<n; i++){
        ans += upper_bound(y.begin(), y.end(), x[i]) - lower_bound(y.begin(), y.end(), x[i]);
    }
    cout << ans << endl;
    return 0;
}