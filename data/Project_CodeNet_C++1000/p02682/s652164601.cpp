#include<iostream>
using namespace std;

int main() {
    int A, B, C, K; cin >> A >> B >> C >> K;
    int ans = 0;
    while(1) {
        if (K == 0) {
            break;
        }
        if (A > 0) {
            A--;
            K--;
            ans++;
        } else if (B > 0) {
            B--;
            K--;
        } else {
            C--;
            K--;
            ans--;
        }
    }
    cout << ans << endl;
}
