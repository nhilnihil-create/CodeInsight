#include <iostream>
using namespace std;
int N, g[500][500];

int main() {
    cin >> N;
    for(int src = 0; src < N; ++src) {
        for(int dst = src + 1; dst < N; ++dst) {
            int bit = 0;
            while((src & (1<<bit)) == (dst & (1<<bit))) ++bit;
            g[src][dst] = bit;
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            cout << g[i][j] + 1 << (j==N-1?'\n':' ');
        }
    }
    return 0;
}