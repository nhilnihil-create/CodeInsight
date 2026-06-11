#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, L, R;
    cin >> L >> R >> d;
    int count = 0;
    for(int i = L; i <= R; i++) {
        if(i%d == 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}