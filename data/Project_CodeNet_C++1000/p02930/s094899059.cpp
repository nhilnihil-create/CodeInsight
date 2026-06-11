#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using std::vector;
using std::printf;
using std::cout;
using std::endl;
using std::string;
using std::cin;

#define i64t long long int
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

template<typename T>
void dump(vector<T> vec) {
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// ---------------------------

const i64t MOD = 1000000007;

vector< vector<int> > edg;

int main() {
    int N;
    cin >> N;

    edg = vector< vector<int> >(N+1);
    for (int i = 0; i < N+1; ++i) {
        edg[i] = vector<int>(N+1, -1);
    }

    // set_level(1, 1, 0, N);

    int xor_ij;
    for (int i = 1; i <= N-1; ++i) {
        for (int j = i+1; j <= N; ++j ) {
            xor_ij = i ^ j;
            // printf("DEBUG : %d %d %x\n", i, j, xor_ij);
            for (int k = 1; k < 500; ++k) {
                // printf("DEBUG2 : %d %d\n", xor_ij, xor_ij & (1 << (k-1)));
                if (xor_ij & (1 << (k-1))) {
                    printf("%d", k);
                    break;
                }
            }
            // printf("%d", edg[i][j]);
            if (j != N) { printf(" "); }
        }
        printf("\n");
    }
}