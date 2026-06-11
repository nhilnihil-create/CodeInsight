#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    string ans;
    while (true) {
        C -= B;
        A -= D;
        if (C <= 0) {
            ans = "Yes";
            break;
        }
        if (A <= 0) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}