#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    for (int i = min(A, B); i <= max(A, B); ++i) {
        if (abs(A - i) == abs(B - i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%s\n", "IMPOSSIBLE");
}
