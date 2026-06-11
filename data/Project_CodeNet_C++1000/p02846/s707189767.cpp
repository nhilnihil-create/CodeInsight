#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;



int main(){
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;
    long long P, Q;
   
    P = (A1-B1) * T1;
    Q = (A2-B2) * T2;
    if (P<0) {
        P = -P;
        Q = -Q;
    }
    if (P+Q==0) {
        cout << "infinity" << endl;
        return 0;
    }
    if (P+Q>0) {
        cout << "0" << endl;
        return 0;
    }
    
    long long v = 2*(P/(-Q-P))+1;
    if (P%(-Q-P)==0) {
        v--;
    }
    
    cout << v << endl;
    
    return 0;
}
