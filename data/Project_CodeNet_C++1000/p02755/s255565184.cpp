#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;
    
    for(int i = 0; i < 20*A; i++) {
        if((i*8)/100 == A && (i*10)/100 == B) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}