#include <iostream>

#define ll long long

const ll int lim = 1e9 + 7;
int H, N, tmp, a[1000], b[1000], out[10001];
 
void solve() {
    std::cin >> H >> N;
    for (int i=0; i<N; ++i)
        std::cin >> a[i] >> b[i];
    for (int i=0; i<10001; ++i)
        out[i] = lim*2;
    out[0] = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<H; ++j) {
            tmp = std::min(H, j + a[i]);
            if (out[tmp] > (out[j] + b[i]))
                out[tmp] = out[j] + b[i];
        }
    }
    std::cout << out[H] << std::endl;
}
 
int main() {
    std::ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
