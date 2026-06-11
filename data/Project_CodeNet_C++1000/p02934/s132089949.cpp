#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double base = 0.00;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        base += 1.00/a[i];
    }
    cout << setprecision(16) << 1.00/base << endl;

    return 0;
}