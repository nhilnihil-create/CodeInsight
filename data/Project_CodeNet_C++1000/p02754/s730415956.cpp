#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    cout << (N/(A + B))*A + (N%(A + B) >= A)*A + (N%(A + B) < A)*(N%(A + B))<< endl;

    return 0;
}