#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll T1, T2;
    cin >> T1 >> T2;
    ll A1, A2;
    cin >> A1 >> A2;
    ll B1, B2;
    cin >> B1 >> B2;
    ll sa1 = T1 * B1 - T1 * A1;
    ll sa2 = T2 * B2 - T2 * A2;
    if (sa1 > 0 && sa1 + sa2 > 0) cout << 0 << endl;
    else if (sa1 < 0 && sa1 + sa2 < 0) cout << 0 << endl;
    else if (sa1 + sa2 == 0) cout << "infinity" << endl;
    else if (sa1 > 0){
        ll real_sa = abs(abs(sa2) - sa1);
        if (sa1 % real_sa == 0) cout << 2 * (sa1 / real_sa) << endl;
        else cout << 2 * (sa1 / real_sa) + 1 << endl;
    }
    else if (sa1 < 0){
        ll real_sa = abs(sa2 + sa1);
        if (sa1 % real_sa == 0) cout << 2 * (abs(sa1) / real_sa) << endl;
        else cout << 2 * (abs(sa1) / real_sa) + 1 << endl;
    }
}