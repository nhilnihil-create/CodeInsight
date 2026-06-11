#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i=0; i < n; i++) cin >> vec.at(i);
    
    int x = 1000000000;
    int ng = 0;

    while (x-ng > 1) {
        int m = (x-ng)/2+ng;
        int cnt = 0;
        for (int i: vec) {
            int times = (i+m-1)/m-1;
            cnt += times;
        }
        if (cnt <= k) x = m;
        else ng = m;
    }

    cout << x << endl;
    return 0;
}