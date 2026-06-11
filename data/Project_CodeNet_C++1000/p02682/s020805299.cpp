#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007


int main(){
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    int ans = 0;
    ans += min(A,K);
    if(K>(A+B)) {
        cout << ans - min(K-A-B,C) << endl;
    }else {
        cout << ans << endl;
    }

    
    return 0;
}