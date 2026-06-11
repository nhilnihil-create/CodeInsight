#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ll N;
    cin >> N;
    ll t;
    ll  ans= 1;

    for(ll i = 0; i < N; i++){
        cin >> t;
        if(ans > 1000000000000000000/t) {
            for(int j = i + 1; j < N; j++) {
                cin >> t;
                if(t) {
                    continue;
                }
                cout << 0 << endl;
                return 0;
            }
            cout << -1 << endl;
            //cout << i << ',' << t << endl;
            return 0;
        }
        ans *= t;

    }
    cout << ans << endl;
}