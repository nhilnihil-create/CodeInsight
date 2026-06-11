#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    if (K > (N-1)*(N-2)/2) {
        cout << -1 << endl;
        return 0;
    } else {
        printf("%d\n", N-1+(N-1)*(N-2)/2 - K);
        for (int i = 2; i <= N; i++) {
            printf("%d %d\n", 1, i);
        }
        int s = 2;
        int t = s + 1;

        for (int i = 0; i < (N-1)*(N-2)/2 - K; i++) {
            if (t > N) {
                s++;
                t = s + 1;
            }
            printf("%d %d\n", s, t);
            t++;
        }
    }
}
