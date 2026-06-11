#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < N; i++)
#define rep2(i, x, n) for (int i = x; i < N; i++)
using ll = long long int;
int main() {
    int N=0;
    cin >> N;
    int P = N / 1000 + 1;
    if (N % 1000 != 0) cout << 1000 * P - N << endl;
    else cout << "0" << endl;
    return 0;
}