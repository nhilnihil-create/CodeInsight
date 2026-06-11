#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
    return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp ++) : *rp ++;
}
inline int read_int() {
    int x = 0;
    char ch = read_char(), flag = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) {
        ch = read_char();
    }
    if (ch == '-') {
        flag = 1;
        ch = read_char();
    }
    for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
        x = x * 10 + (ch - '0');
    }
    return flag ? -x : x;
}

const int MAX_N = 100000 + 5;

int A, B, M, a[MAX_N], b[MAX_N];
int ans_a, ans_b, ans;

int main() {
    A = read_int();
    B = read_int();
    M = read_int();
    ans_a = 1e9;
    for (int i = 1; i <= A; i ++) {
        a[i] = read_int();
        ans_a = min(ans_a, a[i]);
    }
    ans_b = 1e9;
    for (int j = 1; j <= B; j ++) {
        b[j] = read_int();
        ans_b = min(ans_b, b[j]);
    }
    ans = ans_a + ans_b;
    for (int k = 1; k <= M; k ++) {
        int i = read_int();
        int j = read_int();
        int c = read_int();
        ans = min(ans, a[i] + b[j] - c);
    }
    printf("%d\n", ans);
    return 0;
}