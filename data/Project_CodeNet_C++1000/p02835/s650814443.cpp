#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int all = A+B+C;
    string ans = "win";
    if (all>=22) {
        ans = "bust";
    }
    cout << ans << endl;
}