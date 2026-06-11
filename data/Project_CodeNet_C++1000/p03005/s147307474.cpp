#include <iostream>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    N -= K * 1;
    int maxi = 1;
    if (N > 0 && K > 1) {
        maxi += N;
        printf("%d\n", maxi - 1);
    }
    else printf("%d\n", 0);
}