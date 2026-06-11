#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    int output = 0;
    while (N >= pow(K, output)) {
        output++;
    }

    cout << output << endl;

    return 0;
}
