#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t1, t2;
    ll a1, a2;
    ll b1, b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    ll dif1 = t1 * a1 - t1 * b1;
    ll dif2 = t2 * a2 - t2 * b2;
    if (dif1 == (0-dif2)) {
        // 1サイクルで元に戻る
       cout << "infinity" << endl;
        return 0;
    } else if ((dif1 < 0 && dif1 + dif2 < 0) || (dif1 > 0 && dif1 + dif2 > 0)){
        // 距離は離れるばかり
        cout << 0 << endl;
        return 0;       
    }
    else {
        ll dif = dif1 + dif2;
        ll conf = floor(abs(dif1) / (double)abs(dif));
        if(conf * abs(dif) == abs(dif1))
            cout << conf * 2 << endl;
        else 
            cout << 1 + conf * 2 << endl;
    }
}
