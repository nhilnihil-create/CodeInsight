#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    ll cnt = 0;
    for (int a = 1; a <= N; a++) {
        cnt += (N - 1) / a;
    }
    cout << cnt << "\n";
    return 0;
}