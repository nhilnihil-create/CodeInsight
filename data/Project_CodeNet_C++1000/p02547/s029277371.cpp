#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() { 
    int N, D_1, D_2, count = 0, status = 0;
    cin >> N;
    rep(i, N) {
        cin >> D_1 >> D_2;
        if (D_1 == D_2) {
            ++count;
        } else {
            count = 0;
        }
        if (count == 3) {
            status = 1;
        }
    }
    if (status == 1) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" <<"\n";
    }
    
    return 0;
}
