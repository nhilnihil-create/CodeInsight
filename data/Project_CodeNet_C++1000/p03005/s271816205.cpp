#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

    int n, k;
    cin >> n >> k;

    int a = n - k + 1;
    int b = n / k;
    cout << a - b << endl;

    return 0;
}