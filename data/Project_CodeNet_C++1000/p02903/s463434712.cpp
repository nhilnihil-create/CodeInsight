#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;
 
const int N = 1e3 + 5;
 
int W, H, A, B;
 
int main() {
    scanf("%d%d%d%d", &W, &H, &A, &B);
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            putchar('0' ^ (i < B) ^ (j < A));
        }
        putchar('\n');
    }
    return 0;
}