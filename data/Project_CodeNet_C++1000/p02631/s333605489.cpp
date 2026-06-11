#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int x= 0;
    for(int i = 1; i < n; i++) {
       x = x^a[i];
    }
    cout << x;

    for(int i = 1; i < n; i++) {
        int y=x;
        y= y^a[0];
        y= y^a[i];
        cout << ' ' << y;
    }

    cout << endl;
    return 0;
}