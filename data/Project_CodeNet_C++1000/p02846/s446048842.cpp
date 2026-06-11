#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

int main() {
    vector<ll> t(2);
    cin >> t[0] >> t[1];
    
    vector<ll> a(2);
    cin >> a[0] >> a[1];
    
    vector<ll> b(2);
    cin >> b[0] >> b[1];
    
    ll diff1 = a[0] < b[0] ? t[0] * (b[0] - a[0]) : t[0] * (a[0] - b[0]);
    ll diff2 = a[0] < b[0] ? t[1] * (b[1] - a[1]) : t[1] * (a[1] - b[1]);
    
    // cout << "diff1 = " << diff1 << ", diff2 = " << diff2 << endl;
    
    if(diff1 + diff2 == 0) {
        cout << "infinity" << endl;
    }
    else if(diff1 + diff2 > 0){
        cout << 0 << endl;
    }
    else {
        ll ans = 1 + 2 * (diff1 / -(diff1 + diff2));
        if(diff1 % -(diff1 + diff2) == 0) {
            ans--;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
