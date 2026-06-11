#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,k;
    cin >> n >> k;
    vector<double> p(n);
    
    double y;
    cin >> y;
    p[0] = (y+1)/2;

    for(int i = 1; i < n; i++) {
        double x;
        cin >> x;
        p[i] = p[i-1] + (x+1)/2;
    }

    vector<double> a(n-k+1);
    a[0] = p[k-1];
    for(int i = k; i < n; i++){
        a[i-k+1] = p[i]-p[i-k];
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    cout << fixed << setprecision(10);
    cout << a[0] << endl;

    return 0;
}