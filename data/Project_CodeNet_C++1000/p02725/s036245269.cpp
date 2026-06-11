#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int k, n;
    cin >> k >> n;
    
    vector<int> v;
    int result = k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        if (i > 1) {
            int d = (k - x) + v[i-1];
            if (d < result) {
                result = d;
            }
        }
    }
    
    int d = v[n-1] - v[0];
    if (d < result) {
        result = d;
    }

    cout << result << endl;


    return 0;
}