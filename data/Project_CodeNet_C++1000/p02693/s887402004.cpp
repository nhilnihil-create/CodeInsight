#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int K, A, B;
    cin >> K >> A >> B;
    bool bl = ((A-1) / K != B / K);
    puts(bl ? "OK" : "NG");
    return 0;
}