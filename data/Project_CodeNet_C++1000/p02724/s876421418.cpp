#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int X;
    cin >> X;

    int a = X / 500;
    int b = (X - (X/500) * 500) / 5;

    cout << a * 1000 + b * 5 << endl;

    return 0;
}