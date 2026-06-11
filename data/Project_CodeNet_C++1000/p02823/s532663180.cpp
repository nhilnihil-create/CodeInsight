#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N, A, B;
    ll ans;
    cin >> N >> A >> B;
    if((B - A) % 2 == 0) ans = min((B - A) /2,min(B - 1, N - A));
    else{
        if(A - 1 < N - B){
            ans = min(A + (B - A - 1) / 2, min(B - 1, N - A));
        }else{
            ans = min(N - B + 1 + (B - A - 1) / 2, min(B - 1, N - A));
        }
    }

    cout << ans << endl;
}
