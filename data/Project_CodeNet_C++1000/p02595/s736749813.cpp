#include <bits/stdc++.h>
using namespace std;




























int main () {
    int64_t N, D;
    cin >> N >> D;
    
    int64_t count = 0;
    for (int64_t i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        if (a * a + b * b <= D * D) {
            count++;
        }
    }
    cout << count << endl;

}