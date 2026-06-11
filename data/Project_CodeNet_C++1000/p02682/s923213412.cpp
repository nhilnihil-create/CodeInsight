#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll A,B,C,K;
    cin >> A >> B >> C >> K;
    
    ll ans = 0;
    if(K - A >= 0){
        K -= A;
        ans += A;
        if(K - B >= 0){
            K -= B;
            if(K > 0){
                ans -= K;
            }
        }
    }
    else ans = K;
    cout << ans << endl;
}
