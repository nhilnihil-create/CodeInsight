#include <bits/stdc++.h>
    
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    
    int x; cin >> x;
    vector<int> xs;
    while(x--) {
        int n; cin >> n;
        xs.push_back(n);
    }

    int total = 0;
    for(int i = 2; i < xs.size(); i++) {
        if (xs[i-2] < xs[i-1] && xs[i] > xs[i-1]) {
            total++;
        }
        if (xs[i-2] > xs[i-1] && xs[i] < xs[i-1]) {
            total++;
        }
    }
    cout << total << endl;

    return 0;
}