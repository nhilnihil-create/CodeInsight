#include<bits/stdc++.h>
using namespace std;

int A, B, C, D;

int main() {
    cin >> A >> B >> C >> D;
    int i = 0;
    while (A > 0 && C > 0) {
        if (i % 2 == 0) C -= B;
        else A -= D;
        i++;
    }
    if (A > 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
