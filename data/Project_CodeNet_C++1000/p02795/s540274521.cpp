#include <iostream>
using namespace std;
int main() {
    int H, W, N; cin >> H >> W >> N;
    int M = 0;
    int cnt = 0;
    while(M < N) {
        cnt++;
        M += max(H, W);
    }
    printf("%d\n", cnt);
}