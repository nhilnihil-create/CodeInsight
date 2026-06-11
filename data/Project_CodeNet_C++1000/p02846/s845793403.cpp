#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    ll t1,t2,a1,a2,b1,b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    a1 *= t1;
    a2 *= t2;
    b1 *= t1;
    b2 *= t2;
    if(a1 + a2 == b1 + b2){
        cout << "infinity" << endl;
        return 0;
    }
    if(a1 + a2 < b1 + b2){
        swap(a1, b1);
        swap(a2, b2);
    }
    if(a1 > b1){
        cout << 0 << endl;
        return 0;
    }
    ll c = b1 - a1, d = (a1 + a2) - (b1 + b2);
    if(c % d == 0) cout << 2 * ((c + d - 1) / d) << endl;
    else cout << 2 * ((c + d - 1) / d) - 1 << endl;
    return 0;
}