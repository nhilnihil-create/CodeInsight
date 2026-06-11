#include<bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B; 
//    int ans = A/0.08;
//    if (floor(ans*0.1)==B) cout << ans;
    for (int i=1; i<1250; i++) {
        if (floor(i*0.08)==A && floor(i*0.1)==B) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}