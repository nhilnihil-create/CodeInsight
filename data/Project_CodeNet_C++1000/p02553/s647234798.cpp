#include <bits/stdc++.h>
using namespace std;;
typedef long long ll;

int main(){
    vector<ll> num(4);
    for (int i = 0; i < 4; i++){
        cin >> num.at(i);
    }
    ll ans = num[0]*num[2];
    for (int i = 0; i < 2; i++){
        for (int j = 2; j < 4; j++){
            ans = max(ans,num[i]*num[j]);
        }
    }

    cout << setprecision(18) << ans << endl;
}