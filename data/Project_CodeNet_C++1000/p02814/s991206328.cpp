#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    long long a, l = 1, m, n, p, q;
    bool bad = false;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a;
        a >>= 1;
        p = (-a) & a;
        if (i){
            if (p != q){
                bad = true;
                break;
            }
        }
        else q = p;
        l = (l * a) / __gcd(l, a);
        if (l > m){
            bad = true;
            break;
        }
    }
    if (bad) cout << 0 << '\n';
    else{
        cout << ((m / l) + 1)/2 << '\n';
    }
}
