#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = -1;

    rep(i,1500) {
        int tax8 = i * 8 / 100.0;
        int tax10 = i * 10 / 100.0;
        if (tax8 == A && tax10 == B) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
