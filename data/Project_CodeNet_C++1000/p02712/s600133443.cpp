#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    int64_t all = 0;
    for (int64_t i = 0; i <= N; i++) {
        if (i % 3 != 0 && i % 5 != 0) all += i;
    }
    cout << all << endl;
}