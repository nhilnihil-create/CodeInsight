#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<long long int> H(N, 0);
    for (int i = 0; i < N; i++) cin >> H[i];
    bool T = true;
    for (int i = 0; i < N - 1; ++i) {
        if (H[i] <= H[i + 1]) {
            if (H[i] < H[i + 1]) {
                H[i + 1]--;
            }
            else {
                continue;
            }
        }
        else {
            T = false; break;
        }
    }
    if (T) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}
