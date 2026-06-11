#include <bits/stdc++.h>
using namespace std;

int n,K;
int main () {
    cin>>n;
    K=-1;
    bool ok = false;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (n == i * j) {
                K=1;
            }
        }
    }
    
    if (K == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}