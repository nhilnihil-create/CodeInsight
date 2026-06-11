#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, count, pre ,aft;
    cin >> N >> K;

    count = 0;
    while(N > 0) {
        N = N / K;
        // cout << N << endl;
        count++;
    }
    cout << count << endl;
}
