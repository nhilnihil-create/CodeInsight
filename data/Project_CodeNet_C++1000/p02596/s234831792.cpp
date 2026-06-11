#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); 

    int k; cin >> k;
    int val = 7%k;
    for (int i = 1; i < 1e6 + 10; i++) {
        if (val % k == 0) {
            cout << i << endl;
            return 0;
        }
        val = (val * 10 + 7) % k;
    }

    cout << -1 << endl;


    return 0; 
}

