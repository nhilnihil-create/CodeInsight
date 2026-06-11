#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t A,B;
    cin >> A >> B;

    if((A+B) % 2) cout << "IMPOSSIBLE\n";
    else cout << (A+B)/2 << "\n";
    return 0;
}
