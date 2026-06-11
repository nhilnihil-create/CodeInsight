#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    ll output = N / (A + B) * A;
    if (A >= N % (A + B))
        output += N % (A + B);
    else
        output += A;

    cout << output << endl;
    return 0;
}
