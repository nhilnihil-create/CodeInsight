#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            if(a[i] % 3 != 0 && a[i] % 5 != 0) {
                ok = false;
            }
        }
    }
    if(ok) {
        puts("APPROVED");
    } else {
        puts("DENIED");
    }
    return 0;
}