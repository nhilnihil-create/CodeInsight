#include <iostream>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    int ans = max(A-2*B, 0);
    cout << ans << endl;
}

