#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;

    int64_t even_num = (M + 1) / 2;
    int64_t sep = even_num * 2;
    for (int64_t i = 0; i < even_num; i++) {
        cout << i + 1 << " " << sep - i << endl;
    }

    int64_t right = (N % 2 == 0 ? N - 1 : N);
    for (int64_t i = 0; i < M - even_num; i++) {
        cout << sep + 1 + i << " " << right - i << endl;
    }
}