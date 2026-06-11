#include <bits/stdc++.h>
using namespace std;

int main(void){
    int P,Q,R;
    cin >> P >> Q >> R;
    
    int A = P + Q;
    int B = Q + R;
    int C = R + P;
    
    int ans = min({A,B,C});
    cout << ans << endl;
}