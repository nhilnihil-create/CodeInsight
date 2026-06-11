#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, ans;
    cin >> A >> B;
    ans = -1;
    for (int i = 1; i <= 1000; i++) {
        if ((int)(i*0.08) == A && (int)(i*0.1) == B) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

}
