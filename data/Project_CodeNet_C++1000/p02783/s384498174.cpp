#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int H, A;
    cin >> H >> A;
    int ans = 0;
    if(H%A==0) {
        ans = H/A;
    }
    else {
        ans = H/A + 1;
    }
    cout << ans << endl;
}