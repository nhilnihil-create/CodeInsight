#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    ll N, A, B;
    cin >> N >> A >> B;

    ll C = A + B;

    cout << (N / C) * A + min(N%C, A) << endl;

    return 0;
}