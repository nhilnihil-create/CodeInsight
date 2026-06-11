#include <bits/stdc++.h>


using namespace std;
using ll = long long;

const int sz = 2e5 + 10;
int a[sz];
int n, k, tmp;

bool work(int p) {
    int cuts = 0;
    for(int i = 0; i < n; i++) {
        int c = a[i] / p;
        if((c * p) == a[i]) {
            cuts += c - 1;
        } else {
            cuts += c;
        }
    }
    return cuts <= k;
}


int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1e9;
    while(l < r) {
        int mid = (l + r) / 2;
        if(work(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << "\n";




    return 0;
}

