
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int64_t N, K;
    cin >> N >> K;


    // translate
    u_int64_t ans = 0;
    for (u_int64_t i = K; i <= N+1; i++) {
        // max - min + 1 で値の個数
        // O(n^2) は怖いので, 和の公式を使う
        // 初項 a から i 個足すとき
        // a + … + a + (i - 1) = i/2 * (a + a + i - 1)
        // 
        // max は大きい方から i 個選択
        // N, N - 1 , … , N - (i - 1)
        // 整数同士の除算を挟む場合, 順番に注意
        u_int64_t max = i * ((N - i + 1) + N) / 2;
        // min は小さい方から i 個選択
        u_int64_t min = i * (0 + 0 + i - 1) / 2;
        u_int64_t count = max - min + 1;
        count %= 1000000000 + 7;
        ans += count;
        ans %= 1000000000 + 7;
        // cout << i << "-selected - > " << count << endl;
    }

    ans %= 1000000000 + 7;

    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
