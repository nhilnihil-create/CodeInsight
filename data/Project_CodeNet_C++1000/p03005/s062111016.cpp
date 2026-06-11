#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    cout <<  abs(n/k - n/k - n%k);

    return 0;
}

