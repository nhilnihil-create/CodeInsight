#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A, B;
    cin >> A >> B;
    if(A < 10 && B < 10) {
        cout << A * B << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
