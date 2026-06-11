#include <cmath>
#include <cstdio>
using namespace std;
int N, sum, o[1000010];
char a[1000010];
int main() {
    scanf("%d%s", &N, a + 1);
    for (int i = 1; i < N; ++i) a[i] = abs(a[i + 1] - a[i]);
    --N;
    if (N == 1) {
        printf("%d\n", (int)a[1]);
        return 0;
    }
    o[1] = 0;
    for (int i = 2; i <= N; ++i) {
        int mul = N - i + 1, div = i - 1;
        o[i] = o[i - 1];
        while (!(mul & 1)) {
            mul >>= 1;
            ++o[i];
        }
        while (!(div & 1)) {
            div >>= 1;
            --o[i];
        }
    }
    for (int i = 1; i <= N; ++i) o[i] = !o[i];
    for (int i = 1; i <= N; ++i) {
        sum += o[i] * a[i];
    }
    if (sum & 1) {
        puts("1");
        return 0;
    }
    sum = 0;
    for (int i = 1; i <= N; ++i) {
        if (a[i] == 1) {
            sum = 1;
            break;
        }
    }
    if (sum) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= N; ++i) sum += o[i] * (a[i] == 2);
    puts(sum & 1 ? "2" : "0");
    return 0;
}
