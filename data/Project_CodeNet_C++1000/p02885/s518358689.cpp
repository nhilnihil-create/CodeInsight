#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = A - 2*B;
    if (ans<0) ans = 0;
    cout << ans << endl;
}