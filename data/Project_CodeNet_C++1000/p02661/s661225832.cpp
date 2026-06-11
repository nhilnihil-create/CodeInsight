#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 1){
        x = b[n / 2] - a[n / 2] + 1;
    }
    else {
        int A, B;
        A = a[n / 2] + a[n / 2 - 1];
        B = b[n / 2] + b[n / 2 - 1];
        x = B - A + 1;
    }
    cout << x << endl;
}