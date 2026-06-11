#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int N, D; cin >> N >> D;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int X, Y; cin >> X >> Y;
        if (pow(X, 2) + pow(Y, 2) <= pow(D, 2)) {
            ans++;
        }
    }
    cout << ans << endl;
}
