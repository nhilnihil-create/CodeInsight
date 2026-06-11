#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
        ll a, b, k;
        cin >> a >> b >> k;
        if(k <= a) cout << a - k << " " << b << endl;
        else {
                ll new_b = a + b - k;
                new_b = new_b >= 0 ? new_b : 0;
                cout << 0 << " " << new_b << endl;
        }
        return 0;
}
