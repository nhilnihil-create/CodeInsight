#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    if(C > A - B) {
        cout << C - (A - B) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
