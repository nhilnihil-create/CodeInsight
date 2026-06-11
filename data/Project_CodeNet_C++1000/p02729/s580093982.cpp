#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    int output = 0;
    output += M * (M - 1) / 2;
    output += N * (N - 1) / 2;

    cout << output << endl;

    return 0;
}
