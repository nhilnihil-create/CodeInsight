#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, K, ans = 0;
    cin >> A >> B >> C >> K;

    if(K <= A){
        ans += K;
        cout << ans << endl;
        return 0;
    } else if(A < K){
        ans += A;
        K -= A;
    }

    if(K <= B){
        cout << ans << endl;
        return 0;
    } else if(B < K){
        K -= B;
    }

    ans -= K;

    cout << ans << endl;

    return 0;
}